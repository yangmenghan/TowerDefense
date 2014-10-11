#include "Player.h"
#include "Config.h"

Player::Player(){
	money = INIT_MONEY;
	hp = INIT_HP;
	score = 0;
};


void Player::manageMoney(int m){
	money = money + m;
};

void Player::manageScore(int s){
	score = score + s;
};

void Player::manageHP(int h){
	hp = hp + h;
};
