#pragma once
#include "Enemy.h"
#include <SFML\Graphics.hpp>

using namespace std;

//! Class of normal enemy
/*! Enemy with normal speed and normal HP */
class NormalEnemy : public Enemy{
public:
	//! normal constructor. 
	NormalEnemy();

	//! constructor with specific caracteristics
	/*!
	\param hp Enemy's maximum hp, integer
	\param defence Enemy's defence, float value, not used yet
	\param bounty integer money that the player get when the enemy is killed
	\param scoreValue integer number of point that the player get when the enemy is killed
	\param sprite sf::Sprite, sprite of the enemy
	\param speed speed of the enemy, float value
	*/
	NormalEnemy(int hp, float defence, int bounty, int scoreValue, sf::Sprite sprite, float speed);
	
	//! normal destructor.
	~NormalEnemy(){};
};