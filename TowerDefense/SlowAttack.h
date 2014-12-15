#pragma once
#include "Attack.h"

//! Derived class from Attack class for SlowTowers' attack action.
/*!
Inheritted form Attack and used by SlowTower.
*/
class SlowAttack :
	public Attack
{
public:

	//! SlowAttack constructor.
	SlowAttack();

	//! SlowAttack destructon.
	~SlowAttack(){};

	//! An overriden function to deal with the animation of the slow attack action.
	/*!
	\param w a sf::RenderWindow reference argument.
	\return void
	*/
	void attackAnimation(sf::RenderWindow& w) override;

	//! An overriden function to deal with the process of the slow attack action.
	/*!
	\param w a sf::RenderWindow reference argument.
	*/
	void resolve(sf::RenderWindow& w) override;
};

