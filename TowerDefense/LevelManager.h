#pragma once
#include "Enemy.h"
#include "Tower.h"
#include "Player.h"
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;

class LevelManager{
public:
	LevelManager getLevelManager();
	Player getPlayer();

	void kill();

	void gameLoop();
	void addEnemy(Enemy);
	void removeEnemy(Enemy);
	void addTower(Tower);
	void removeTower(Tower);

	static LevelManager levelManager;
private:
	vector<Enemy> enemies;
	vector<Tower> towers;
	Player player;
};