#pragma once
#include "Enemy.h"
#include "Tower.h"
#include <vector>
#include <memory>
#include <SFML\Graphics.hpp>

using namespace std;

class LevelManager{
public:
	
	void kill();

	void gameLoop();
	void addEnemy(Enemy);
	void removeEnemy(Enemy);
	void removeEnemy(int);
	void addTower(Tower);
	void removeTower(Tower);
	void removeTower(int);

	vector<Enemy>* getEnemies();
	vector<Tower>* getTowers(); 
	LevelManager* getLevelManager();

	static LevelManager* levelManager;
private:
	LevelManager();
	~LevelManager();
	vector<Enemy> enemies;
	vector<Tower> towers;
};