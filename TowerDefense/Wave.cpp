#include "Wave.h"
#include "Config.h"
#include "NormalEnemy.h"
#include "ToughEnemy.h"
#include "BombEnemy.h"
#include "FastEnemy.h"
#include "LevelManager.h"

Wave::Wave(){
	spawnCooldown = WAVE_SPAWN_COOLDOWN;
};

Wave::Wave(vector<shared_ptr<Enemy>> e){
	enemies = e;
};

void Wave::addEnemy(char type){
	//TODO : warning modularity
	if (type == '1'){
		NormalEnemy e;
		enemies.push_back(make_shared<NormalEnemy>(e));
		return;
	}
	else if (type == '2'){
		FastEnemy e;
		enemies.push_back(make_shared<FastEnemy>(e));
		return;
	}
	else if (type == '3'){
		ToughEnemy e;
		enemies.push_back(make_shared<ToughEnemy>(e));
		return;
	}
	else if (type == '4'){
		BombEnemy e;
		enemies.push_back(make_shared<BombEnemy>(e));
		return;
	}

}

Wave::Wave(int lineNumber){
	//TODO : create a wave from a line of wave config file
};

// if the cooldown is done, the return the last enemy of the wave and delete it from the list
// if the wave is empty the call the nextWave Function of levelmanager
// if the cooldown is not done, continue the Zcooldown

shared_ptr<Enemy> Wave::spawnEnemy(){
	if (spawnCooldown == 0){
		spawnCooldown = WAVE_SPAWN_COOLDOWN;
		if (!enemies.empty()){
			shared_ptr<Enemy> e = enemies.back();
			enemies.pop_back();
			return e;
		}
		else {
			LevelManager::getLevelManager()->nextWave();
		}
		
	}
	else {
		spawnCooldown--;
	}
	return NULL;
};

// return the number of frames remaining before the next enemy spawn
int Wave::getSpawnCooldown(){
	return spawnCooldown;
};