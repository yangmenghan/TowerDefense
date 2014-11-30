#pragma once
#include "Enemy.h"
#include <SFML\Graphics.hpp>

using namespace std;

class NormalEnemy : public Enemy{
public:
	NormalEnemy();
	NormalEnemy(int hp, float defence, int bounty, int scoreValue, sf::Sprite sprite, float speed);
	virtual ~NormalEnemy(){};

	string test(){ return ""; };
};