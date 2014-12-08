#include "LevelManager.h"
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
	startGame();
}

LevelManager::~LevelManager(){
}

void LevelManager::gameLoop(RenderWindow& w){
		field.draw(w);
		//currentPath.draw(w);

		//field.computePath(field.getStartTile(), field.getEndTile()).draw(w);

		//if the game is not paused
		if (gameSpeed != 0){ 


			/*for (Tile tile : field.getTiles()) {
				if (tile.hasOpenedMenu()) {
					tile.getCurrentMenu().draw(w);
					tile.getCurrentMenu().resolveEvents();
				}
			}
			*/



			if (player.getHP() <=0){
				gameOver(); 
			}
			

			if (waves.size() == 0){
				if (enemies.empty()){
					victory(); // you win if there is no enemy and no wave left
				}
			}
			else { 
				//TODO : memory???
				waves.back().spawnEnemy();

				
			}
			

			//Tower actions
			for (int i = 0; i < towers.size(); i++){
				if (towers.at(i)->getLevel() ==0){
					towers.at(i)->getTile()->setTower(NULL);
					removeTower(i);
					i--;
				}
				else {
					towers.at(i)->doAttack();
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
					player.manageHP(-1);
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
	//TODO
}

void LevelManager::gameOver(){
	//TODO
}

void LevelManager::startGame(){
	loadWaves();
	//player = Player();
	//player.init();
	currentPath = field.computePath(field.getStartTile(), field.getEndTile());
}

void LevelManager::stopGame(){
	gameSpeed = 0;
	field = Field();
	waves.clear();
	enemies.clear();
	towers.clear();

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

void LevelManager::setPlayer(Player &p){
	player = p;
};
void LevelManager::setField(Field &f){
	field = f;
};

Player*	LevelManager::getPlayer(){
	return &player;
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