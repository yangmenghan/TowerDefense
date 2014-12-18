#pragma once
#include "Enemy.h"
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;

class Wave {
public:
	//! normal constructor
	Wave();

	//!create a wave with the given vector of enemies
	Wave(vector<shared_ptr<Enemy>> enemies);
	
	//! create a wave with the Ne line of the wave txt file
	Wave::Wave(int lineNumber);

	//spawn a new enemy in game
	/*!
		add a new enemy in the levelmanager's enemies vector and delete it in the wave.
		\sa LevelManager::gameLoop()
	*/
	void spawnEnemy();

	//!add a new enemy in the wave
	/*!
		add a new enemy with specified type the in wave
		\param char value of the type of enemy to create : 1-normal enemy 2- fast enemy 3- tough enemy 4- bomb enemy
	*/
	void addEnemy(char type);

	//! get int value of remaining cooldown before next enemy spawn
	int getSpawnCooldown();

private:
	//! int value of remaining cooldown before next enemy spawn
	int spawnCooldown;

	//! vector of enemies in the wave
	vector<shared_ptr<Enemy>> enemies;

};