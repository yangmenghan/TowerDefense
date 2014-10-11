#pragma once
#include "Enemy.h"
#include "Tower.h"
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;

class LevelManager{
public:
	LevelManager();
	LevelManager(int hp, float defence, int bounty, int scoreValue, sf::Sprite sprite, float speed);
	~LevelManager();

	void gameLoop();
	void addEnemy(Enemy);
	void removeEnemy(Enemy);
	void addTower(Tower);
	void removeTower(Tower);

private:
	vector<Enemy> enemies;
	vector<Tower> towers;
};