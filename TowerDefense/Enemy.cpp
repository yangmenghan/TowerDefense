#include "Enemy.h"
#include "Config.h"

/*
private:
int hp;
float defence;
int bounty;
int scoreValue;
int slowTime;
*/

Enemy::Enemy(){
	hp = 0;
	defence = 0;
	bounty = 0;
	scoreValue = 0;
	speed = 0;
}


Enemy::Enemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed){
	hp = mHP;
	defence = mDefence;
	bounty = mBounty;
	scoreValue = mScoreValue;
	speed = mSpeed;
	sprite = mSprite;
}

float Enemy::getDistanceToTarget(){
	return LevelManager::getLevelManager().getField().tempCross(tile, LevelManager::getLevelManager().getField().getEndTile());
};

bool Enemy::move(){
	if (slowTime > 0){
		slowTime--;
	}
	else {
		unSlow();
	}

	vector<Tile*> tiles = LevelManager::getLevelManager().getField().computePath(tile, LevelManager::getLevelManager().getField().getEndTile()).getPath();
	Tile t = *tiles[0];
	int gameSpeed = LevelManager::getLevelManager().getSpeed();
	position.x = position.x + gameSpeed * speed;
	position.y = position.y + gameSpeed * speed;
	return true;
};

void Enemy::succed(){
	LevelManager::getLevelManager().getPlayer().manageHP(-1);
	dieWithoutBonus();
};

void Enemy::setTile(Tile t){
	tile = t;
	position = t.getPosition();
}


void Enemy::die(){
	LevelManager::getLevelManager().getPlayer().manageScore(scoreValue);
	this->~Enemy();
};

void Enemy::dieWithoutBonus(){
	this->~Enemy();
}

void Enemy::slow(int frames){
	slowTime = frames;
	speed = speed - ;
};

void Enemy::slow(int frames){
	slowTime = frames;
	speed = speed - SLOW_EFFECT;
};

void Enemy::unSlow(){
	speed = speed + SLOW_EFFECT;
};

void Enemy::takeDamage(int damage){
	hp = hp - damage;
};



// Getters and Setters

int Enemy::getHP(){
	return hp;
};
int Enemy::getBounty(){
	return bounty;
};

int Enemy::getScoreValue(){
	return scoreValue;
};
float Enemy::getDefence(){
	return defence;
};

int Enemy::getSlowTime(){
	return slowTime;
};



