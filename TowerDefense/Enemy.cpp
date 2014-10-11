#include "Enemy.h"

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

bool Enemy::move(){

};

void Enemy::succed(){
};


void Enemy::die(){
};

void Enemy::slow(int seconds){
	slowTime = seconds;
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



