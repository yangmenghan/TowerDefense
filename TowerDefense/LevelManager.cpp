#include "LevelManager.h"
#include "MenuManager.h"
#include <fstream>

using namespace sf;

LevelManager* LevelManager::getLevelManager(){
	if (NULL == levelManager)
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

LevelManager::LevelManager(){
	waveCooldown = WAVE_COOLDOWN;
	loadWaves();
}

void LevelManager::gameLoop(RenderWindow& w){
	sf::Event event;
	while (w.pollEvent(event)){
		w.clear();
		
		/*
		if (event == ""){
			//TODO
		}
		
		else {*/

			if (event.type == sf::Event::Closed){
				w.close();
				//TODO : stop the game !!
			}
				
		

		MenuManager::getMenuManager()->display(w);
		MenuManager::getMenuManager()->resolveEvent(event);

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
					waves.back().spawnEnemy();
				
			}
			

			//Tower actions
			for (Tower* tower : towers){
				tower->draw(w);
				tower->doAttack();
			}

			//Enemy Action
			for (Enemy* enemy : enemies){
				if (enemy->getHP() <= 0){
					enemy->die();
				}
				else if (enemy->getPosition() == field.getEndTile()->getPosition()){
					removeEnemy(*enemy);
					enemy->succed();
				}
				else {
					enemy->move(); 
					enemy->draw(w);
				}
			}
			
		}
		
		w.display(); 
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

void LevelManager::addEnemy(Enemy &e){
	e.setTile(*field.getStartTile());
	enemies.push_back(&e);
};

void LevelManager::removeEnemy(Enemy e){
	remove(enemies.begin(), enemies.end(), &e);
};

void LevelManager::removeEnemy(int index){
	enemies.erase(enemies.begin() + index);
};

void LevelManager::addTower(Tower &t){
	towers.push_back(&t);
};

void LevelManager::removeTower(Tower t){
	remove(towers.begin(), towers.end(), &t);
};

void LevelManager::removeTower(int index){
	towers.erase(towers.begin()+index);
};

vector<Enemy*> LevelManager::getEnemies(){
	return enemies;

}

vector<Tower*> LevelManager::getTowers(){
	return towers;
}

void LevelManager::setPlayer(Player &p){
	player = p;
};
void LevelManager::setField(Field &f){
	field = f;
};
void LevelManager::setGameMenu(GameMenu &gameMenu){
	gameMenu = gameMenu;
};

Player	LevelManager::getPlayer(){
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