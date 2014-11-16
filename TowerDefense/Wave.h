#pragma once
#include "Enemy.h"
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;

class Wave {
public:
	Wave();
	Wave(vector<Enemy>);
	Wave::Wave(int lineNumber);

	Enemy spawnEnemy();

	void addEnemy(char type);

	int getSpawnCooldown();

private:
	int spawnCooldown;
	vector<Enemy> enemies;

};