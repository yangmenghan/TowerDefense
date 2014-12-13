#include "LevelManager.h"
#include "GameOverMenu.h"
#include <fstream>

using namespace sf;

LevelManager* LevelManager::levelManager = NULL;

LevelManager* LevelManager::getLevelManager(){
	if (levelManager == NULL)
	{
		levelManager = new LevelManager;
	}

	return levelManager;
};

bool LevelManager::ifWin(){
	return waves.empty() && enemies.empty();
}

void LevelManager::kill(){
	if (NULL != levelManager)
	{
		delete levelManager;
		levelManager = NULL;
	}
};

LevelManager::LevelManager()
{
	waveCooldown = WAVE_COOLDOWN;
	player = make_shared<Player>();
	startGame();
}

LevelManager::~LevelManager(){
}

void LevelManager::updatePath(){
	currentPath = field.computePath(field.getStartTile(), field.getEndTile());
	for (auto e : enemies){
		e->updatePath();
	}
}

void LevelManager::gameLoop(RenderWindow& w){
		field.draw(w);
		currentPath.draw(w);

					
		//if the game is not paused
		if (gameSpeed != 0){ 

			if (player->getHP() <= 0){
				gameOver();
				return;
			}
			else if (waves.size() == 0 && enemies.empty()){
				victory();		// you win if there is no enemy and no wave left
				return;
			}
			else { 
				//TODO : memory???
				waves.back().spawnEnemy();
			}

			//Tower actions
			for (int i = 0; i < towers.size(); i++){
				if (towers.at(i)->getLevel() == 0){
					towers.at(i)->getTile()->setTower(NULL);
					removeTower(i);
					updatePath();
					i--;
				}
				else {
					towers.at(i)->doAttack(w);
				}
			}

			//Enemy Action
			for (int i = 0; i < enemies.size(); i++){
				if (enemies.at(i)->getHP() <= 0){
					enemies.at(i)->die();
					removeEnemy(i);
					i--;
				}
				else if (enemies.at(i)->getPosition() == field.getEndTile()->getPositionPixel()){
					enemies.at(i)->succed();
					removeEnemy(i);
					i--;
				}
				else {
					enemies.at(i)->move();
				}
			}
			
		}
		//Tower actions
		for (shared_ptr<Tower> tower : towers){
			tower->draw(w);
		}

		for (int i = 0; i < enemies.size(); i++){
			enemies.at(i)->draw(w);
		}
};


//proceed to the terminaison of current wave and pop the next wave
void LevelManager::nextWave(){
	if (enemies.empty()){ // the spawn of the next wave start if there is no enemy left on the map
		if (waveCooldown != 0){
			waveCooldown--;
		}
		else {
			waveCooldown = WAVE_COOLDOWN;
			waves.pop_back();
		}
	}
	
}

//load
void LevelManager::loadWaves(){
	string address = WAVE_FILE_ADDRESS;
	ifstream file(address);

	string line;
	while (std::getline(file, line))
	{
		Wave w;
		for (char type: line){
			w.addEnemy(type);
		}
		waves.push_back(w);
	}
	file.close();
}

void LevelManager::victory(){
	setSpeed(0);
	MenuManager::getMenuManager()->addMenu(make_shared<GameOverMenu>(WIN_MENU_TEXTURE, sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT), sf::Vector2i(0, 0)));
}

void LevelManager::gameOver(){
	setSpeed(0);
	MenuManager::getMenuManager()->addMenu(
		make_shared<GameOverMenu>(GAMEOVER_MENU_TEXTURE, sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT), sf::Vector2i(0, 0)));
}

void LevelManager::startGame(){
	gameSpeed = 1;
	loadWaves();
	updatePath();
	player->init();
}

int LevelManager::stopGame(){
	gameSpeed = 0;
	field = Field();
	waves.clear();
	enemies.clear();
	towers.clear();
	return player->getScore();
}

void LevelManager::restartGame(){
	stopGame();
	startGame();
}

void LevelManager::addEnemy(shared_ptr<Enemy> e){
	e->setTile(field.getStartTile());
	enemies.push_back(e);
};

void LevelManager::removeEnemy(shared_ptr<Enemy> e){
	enemies.erase(remove(enemies.begin(), enemies.end(), e), enemies.end());
};

void LevelManager::removeEnemy(int index){
	enemies.erase(enemies.begin() + index);
};

void LevelManager::addTower(shared_ptr<Tower> t){
	towers.push_back(t);
};

void LevelManager::removeTower(shared_ptr<Tower> t){
	towers.erase(remove(towers.begin(), towers.end(), t), towers.end());
};

void LevelManager::removeTower(int index){
	towers.erase(towers.begin()+index);
};

vector<shared_ptr<Enemy>> LevelManager::getEnemies(){
	return enemies;
}

vector<shared_ptr<Tower>> LevelManager::getTowers(){
	return towers;
}

void LevelManager::setPlayer(shared_ptr<Player> p){
	player = p;
};
void LevelManager::setField(Field &f){
	field = f;
};

shared_ptr<Player> LevelManager::getPlayer(){
	return player;
}

Field LevelManager::getField(){
	return field;
}

int LevelManager::getSpeed(){
	return gameSpeed;
}
void LevelManager::setSpeed(int speed){
	gameSpeed = speed;
}

int LevelManager::getCurrentWaveNumber(){
	return (WAVE_TOTAL - waves.size());
}