#pragma once
#include "Enemy.h"
#include "Tower.h"
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;

class LevelManager{
public:
	LevelManager getLevelManager();
	void kill();

	void gameLoop();
	void addEnemy(Enemy);
	void removeEnemy(Enemy);
	void addTower(Tower);
	void removeTower(Tower);

	static LevelManager levelManager = NULL;
private:
	vector<Enemy> enemies;
	vector<Tower> towers;
};