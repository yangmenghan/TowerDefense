#include "BombEnemy.h"
#include "Config.h"
#include "Tile.h"


BombEnemy::BombEnemy(){
	hp = BOMB_ENEMY_HP;
	defence = BOMB_ENEMY_DEFENCE;
	bounty = BOMB_ENEMY_BOUNTY;
	scoreValue = BOMB_ENEMY_SCOREVALUE;
	speed = BOMB_ENEMY_SPEED;

	sf::Texture texture;
	if (!texture.loadFromFile(BOMB_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
}

BombEnemy::BombEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, int mTrigger, sf::Sprite mSprite, float mSpeed){
	Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed); 
	trigger = mTrigger;
}

BombEnemy::~BombEnemy(){
};

int BombEnemy::getTrigger(){
	return trigger;
};

int BombEnemy::getTimer(){
	return timer;
};

bool BombEnemy::move(){
	if (hp <= trigger){
		//TODO : manage the countdown
		if (hp<=0){
			explode();
		}
	}
	else {
		return Entity::move();
		//TODO : verify the syntax
	}
}

void BombEnemy::explode(){
	//TODO : get tiles ...
	Field f = LevelManager::getLevelManager().getField();
	vector<Tile*> t = tile.getNeighbor(1);
	t.push_back(tile);
	for (Tile* tile : t){
		tile->setCooldown(TILE_COOLDOWN);
	}

	//TODO : ...and enemies...
	vector<Enemy*> e = LevelManager::getLevelManager().getEnemies();
	vector<Enemy*> enemies;
	for (Enemy* en : e){
		for (Tile* temp_tile : t){
			if (en->getTile().getPosition == (*temp_tile).getPosition){
				enemies.push_back(en);
			}
		}

	}

	for (Enemy* e : enemies){
		e->dieWithoutBonus();
	}

	//TODO : ...and towers.
	vector<Tower*> t2 = LevelManager::getLevelManager().getTowers();
	vector<Tower*> towers;
	for (Tower* temp_tower: t2){
		for (Tile* temp_tile : t){
			if (temp_tower->getTile().getPosition == (*temp_tile).getPosition){
				towers.push_back(temp_tower);
			}
		}

	}

	for (Tower* t : towers){
		t->downgradeTw();
	}

	dieWithoutBonus();
};

void BombEnemy::TriggerCountDown(){

};

void BombEnemy::checkCountDown(){
};
