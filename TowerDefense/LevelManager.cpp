#include "LevelManager.h"

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

void LevelManager::gameLoop(){
};

void LevelManager::addEnemy(Enemy e){
	enemies.push_back(e);
};

void LevelManager::removeEnemy(Enemy e){
	enemies.erase(std::remove(enemies.begin(), enemies.end(), e), enemies.end());
};

void LevelManager::removeEnemy(int index){
	enemies.erase(enemies.begin() + index);
};

void LevelManager::addTower(Tower t){
	towers.push_back(t);
};

void LevelManager::removeTower(Tower t){
	towers.erase(std::remove(towers.begin(), towers.end(), t), towers.end());
};

void LevelManager::removeTower(int index){
	towers.erase(towers.begin()+index);
};

vector<Enemy>* LevelManager::getEnemies(){
	return &enemies;

}

vector<Tower>* LevelManager::getTowers(){
	return &towers;
}
