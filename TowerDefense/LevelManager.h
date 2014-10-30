#pragma once
#include "Enemy.h"
#include "Tower.h"
#include "Player.h"
#include "Field.h"
#include "GameMenu.h"
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;

class LevelManager{
public:
	LevelManager();
	~LevelManager();

	static LevelManager getLevelManager();
	void kill();

	void gameLoop(sf::RenderWindow& w);
	void addEnemy(Enemy&);
	void removeEnemy(Enemy);
	void removeEnemy(int);
	void addTower(Tower&);
	void removeTower(Tower);
	void removeTower(int);

	vector<Enemy*> getEnemies();
	vector<Tower*> getTowers();
	
	void setPlayer(Player &player);
	Player getPlayer();
	void setField(Field &field);
	Field getField();
	void setGameMenu(GameMenu &gameMenu);
	int getSpeed();
	void setSpeed(int);

	int gameSpeed = 1;

	static LevelManager* levelManager;

private:

	vector<Enemy*> enemies;
	vector<Tower*> towers;

	Player player;
	Field field;
	GameMenu gameMenu;
};