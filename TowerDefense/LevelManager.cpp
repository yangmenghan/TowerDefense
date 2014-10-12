#include "LevelManager.h"

LevelManager LevelManager::getLevelManager(){
	if (NULL == levelManager)
	{
		levelManager = new UniqueObject;
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
};

void LevelManager::addTower(Tower t){
	towers.push_back(t);
};

void LevelManager::removeTower(Tower t){
};
