#pragma once
#include "Enemy.h"
#include <SFML\Graphics.hpp>

using namespace std;

class ToughEnemy : public Enemy{
public:
	ToughEnemy();
	ToughEnemy(int hp, float defence, int bounty, int scoreValue, sf::Sprite sprite, float speed);
	virtual ~ToughEnemy(){};

	string test(){ return ""; };

};