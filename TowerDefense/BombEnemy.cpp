#include "BombEnemy.h"
#include "Config.h"


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
	for (Tile tile : tiles){
		tile.setCooldown(TILE_COOLDOWN);
	}

	//TODO : ...and enemies...
	for (Enemy e : enemies){
		e.dieWithoutBonus();
	}

	//TODO : ...and towers.
	for (Tower t : towers){
		t.downgradeTw();
	}
	dieWithoutBonus();
};

void BombEnemy::TriggerCountDown(){

};

void BombEnemy::checkCountDown(){
};
