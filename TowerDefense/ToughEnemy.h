#pragma once
#include "Enemy.h"
#include <SFML\Graphics.hpp>

using namespace std;

//! Class of tough enemy
/*! Enemy with slow speed and many HP */ 
class ToughEnemy : public Enemy{
public:
	//! normal constructor. 
	ToughEnemy();

	//! constructor with specific caracteristics
	/*! 
	\param hp Enemy's maximum hp, integer
	\param defence Enemy's defence, float value, not used yet
	\param bounty integer money that the player get when the enemy is killed
	\param scoreValue integer number of point that the player get when the enemy is killed
	\param speed speed of the enemy, float value
	*/
	ToughEnemy(int hp, float defence, int bounty, int scoreValue, sf::Sprite sprite, float speed);

	//! normal destructor.
	~ToughEnemy(){};

};