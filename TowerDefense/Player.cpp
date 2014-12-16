#include "Player.h"
#include "Config.h"
#include "AudioManager.h"

Player::Player(){
	money = INIT_MONEY;
	hp = INIT_HP;
	score = 0;
	//init();
};

void Player::init(){
	money = INIT_MONEY;
	hp = INIT_HP;
	score = 0;
}

void Player::manageMoney(int m){
	money = money + m;
};

void Player::manageScore(int s){
	score = score + s;
};

void Player::manageHP(int h){
	hp = hp + h;
	if (h<0){
		AudioManager::getAudioManager()->playSound(SOUND_DAMAGE);
	}
};


int Player::getHP(){
	return hp;
};
int Player::getScore(){
	return score;
};
int Player::getMoney(){
	return money;
};
