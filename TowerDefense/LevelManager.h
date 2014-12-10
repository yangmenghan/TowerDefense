#pragma once
#include "Enemy.h"
#include "Tower.h"
#include "Player.h"
#include "Field.h"
#include "Wave.h"
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;

class LevelManager{
public:

	static LevelManager* getLevelManager();
	void kill();

	void gameLoop(sf::RenderWindow& w);
	void addEnemy(shared_ptr<Enemy> e);
	void removeEnemy(shared_ptr<Enemy> e);
	void removeEnemy(int);
	void addTower(shared_ptr<Tower>);
	void removeTower(shared_ptr<Tower>);
	void removeTower(int);

	vector<shared_ptr<Enemy>> getEnemies();
	vector<shared_ptr<Tower>> getTowers();
	vector<Wave> getWaves();
	
	void setPlayer(shared_ptr<Player> player);
	shared_ptr<Player> getPlayer();

	void setField(Field &field);
	Field getField();

	int getSpeed();
	void setSpeed(int);

	void nextWave();
	void loadWaves(); 

	void updatePath();

	void gameOver(); //TODO
	void victory(); //TODO

	void stopGame();
	void startGame();
	void restartGame();

	int getCurrentWaveNumber();

private:

	LevelManager();
	~LevelManager();
	static LevelManager* levelManager;

	Path currentPath;

	//Cooldowns:
	int waveCooldown;

	//end of cooldowns


	float gameSpeed = 1;

	vector<shared_ptr<Enemy>> enemies;
	vector<shared_ptr<Tower>> towers;
	vector<Wave> waves;

	shared_ptr<Player> player;
	Field field;

};