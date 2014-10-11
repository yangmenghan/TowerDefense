#include "Wave.h"

Wave::Wave(){
};

Wave::Wave(vector<Enemy> e){
	enemies = e;
};

void Wave::spawnEnemy(){
};


int Wave::getSpawnCooldown(){
	return spawnCooldown;
};