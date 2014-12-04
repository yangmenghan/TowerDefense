#pragma once
#include "Enemy.h"
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;

class Wave {
public:
	Wave();
	Wave(vector<shared_ptr<Enemy>>);
	Wave::Wave(int lineNumber);

	void spawnEnemy();

	void addEnemy(char type);

	int getSpawnCooldown();

private:
	int spawnCooldown;
	vector<shared_ptr<Enemy>> enemies;

};