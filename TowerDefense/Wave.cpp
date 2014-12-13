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
		enemies.insert(enemies.begin(), make_shared<NormalEnemy>());
		return;
	}
	else if (type == '2'){
		enemies.insert(enemies.begin(), make_shared<FastEnemy>());
		return;
	}
	else if (type == '3'){
		enemies.insert(enemies.begin(), make_shared<ToughEnemy>());
		return;
	}
	else if (type == '4'){
		enemies.insert(enemies.begin(), make_shared<BombEnemy>());
		return;
	}
	else if (type == '0'){
		enemies.insert(enemies.begin(), NULL);
		return;
	}

}

Wave::Wave(int lineNumber){
	//TODO : create a wave from a line of wave config file
};

// if the cooldown is done, the return the last enemy of the wave and delete it from the list
// if the wave is empty the call the nextWave Function of levelmanager
// if the cooldown is not done, continue the Zcooldown

void Wave::spawnEnemy(){
	if (spawnCooldown <= 0){
		
		if (!enemies.empty()){
			if (enemies.back() == NULL){
				spawnCooldown = WAVE_SPAWN_PAUSE_COOLDOWN;
				enemies.pop_back();
				enemies.shrink_to_fit();
			}
			else {
				spawnCooldown = WAVE_SPAWN_COOLDOWN;
				LevelManager::getLevelManager()->addEnemy(enemies.back());
				LevelManager::getLevelManager()->getEnemies().back()->setTile(LevelManager::getLevelManager()->getField().getStartTile());
				enemies.pop_back();
				enemies.shrink_to_fit();
			}
			
		}
		else {
			LevelManager::getLevelManager()->nextWave();
		}
		
	}
	else {
		spawnCooldown--;
	}
};

// return the number of frames remaining before the next enemy spawn
int Wave::getSpawnCooldown(){
	return spawnCooldown;
};