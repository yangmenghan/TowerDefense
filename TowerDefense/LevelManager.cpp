#include "LevelManager.h"

using namespace sf;

LevelManager LevelManager::getLevelManager(){
	if (NULL == levelManager)
	{
		levelManager = new LevelManager;
	}

	return *levelManager;
};

void LevelManager::kill(){
	if (NULL != levelManager)
	{
		delete levelManager;
		levelManager = NULL;
	}
};

void LevelManager::gameLoop(RenderWindow& w){
	while(w.isOpen){
		w.clear();

		gameMenu.draw(w);
		gameMenu.resolveEvent();

		//if the game is not paused
		if (gameSpeed != 0){ 



			for (Tile tile : field.getTiles()) {
				if (tile.hasOpenedMenu()) {
					tile.getCurrentMenu().draw(w);
					tile.getCurrentMenu().resolveEvents();
				}
			}

			//Tower actions
			for (Tower* tower : towers){
				tower->draw(w);
				if (tower->canAttack()){
					tower->attack();
				}
			}

			//Enemy Action
			for (Enemy* enemy : enemies){
				if (enemy->getHP <= 0){
					removeEnemy(*enemy);
					enemy->die();
				}
				else if (enemy->getPosition == field.getFinalTile().getPosition()){
					removeEnemy(*enemy);
					enemy->succed();
				}
				else {
					enemy->draw(w);
					enemy->move();
				}
			}
			
		}

		else {

		}
		
		w.display();
	}
};

void LevelManager::addEnemy(Enemy &e){
	enemies.push_back(&e);
};

void LevelManager::removeEnemy(Enemy e){
	enemies.erase(std::remove(enemies.begin(), enemies.end(), e), enemies.end());
};

void LevelManager::removeEnemy(int index){
	enemies.erase(enemies.begin() + index);
};

void LevelManager::addTower(Tower &t){
	towers.push_back(&t);
};

void LevelManager::removeTower(Tower t){
	towers.erase(std::remove(towers.begin(), towers.end(), t), towers.end());
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