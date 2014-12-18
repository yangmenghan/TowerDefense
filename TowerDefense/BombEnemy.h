#pragma once
#include "Enemy.h"
#include "Tile.h"
#include <SFML\Graphics.hpp>
#include <vector>

using namespace std;

class BombEnemy : public Enemy{
public:
	//! normal constructor
	BombEnemy();

	//!
	BombEnemy(int hp, float defence, int bounty, int scoreValue, int trigger, sf::Sprite sprite, float speed);
	
	//! normal destructor
	~BombEnemy(){};

	//! return the int value of HP trigger - HP threshold which triggers explosion countdown 
	int getTrigger();

	//! return the int value of slow down effect cooldown 
	int getTimer();

	//! the enemy explodes
	/*!
		called by the bombenemy's move() method when the hp trigger is reached. kill every enemy and downgrade every tower in the bombenemy's range , and pollute the tiles in enemy's range
		\sa Tile
		\sa move()
	*/
	void explode();

	//! the move method of bombEnemy
	/*!
		check if the hp is under the hp trigger : if false, moves the enemy's position, if true, trigger the count down before explosion
	*/
	void move() override;

private:
	//! HP threshold which triggers explosion countdown 
	int trigger;	

	//! number of seconds before explosion
	int timer;	


};