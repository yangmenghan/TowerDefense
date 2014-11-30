#pragma once
#include "Enemy.h"
#include <SFML\Graphics.hpp>

using namespace std;

class FastEnemy : public Enemy{
public:
	FastEnemy();
	FastEnemy(int hp, float defence, int bounty, int scoreValue, sf::Sprite sprite, float speed);
	virtual ~FastEnemy(){};

	string test(){ return ""; };
};