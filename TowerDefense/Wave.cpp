#include "Wave.h"
#include "Config.h"

Wave::Wave(){
	spawnCooldown = WAVE_SPAWN_COOLDOWN;
};

Wave::Wave(vector<Enemy> e){
	enemies = e;
};

void Wave::addEnemy(char type){
	//TODO : warning modularity
	switch type :
	case "1":
		enemies.push_back(NormalEnemy e);
		break;
	case "2":
		enemies.push_back(FastEnemy e);
		break;
	case "3":
		enemies.push_back(ToughEnemy e);
		break;
	case "4":
		enemies.push_back(BombEnemy e);
		break;
}

Wave::Wave(int lineNumber){
	//TODO : create a wave from a line of wave config file
};

// if the cooldown is done, the return the last enemy of the wave and delete it from the list
// if the wave is empty the call the nextWave Function of levelmanager
// if the cooldown is not done, continue the cooldown

Enemy* Wave::spawnEnemy(){ 
	if (spawnCooldown == 0){
		spawnCooldown = WAVE_SPAWN_COOLDOWN;
		if (!enemies.empty()){
			Enemy e = enemies.back();
			enemies.pop_back();
			return e;
		}
		else {
			LevelManager::getLevelManager().nextWave();
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