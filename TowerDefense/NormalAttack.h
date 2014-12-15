#pragma once
#include "Attack.h"

//! Derived class from Attack class for NormalTowers' attack action.
/*!
Inheritted form Attack and used by NormalTower.
*/
class NormalAttack :
	public Attack
{
public:
	//! NormalAttack constructor.
	NormalAttack();

	//! NormalAttack destructon.
	 ~NormalAttack(){};

	//! An overriden function to deal with the animation of the normal attack action.
	 /*!
	 \param w a sf::RenderWindow reference argument.
	 \return void
	 */
	void attackAnimation(sf::RenderWindow& w) override;

	//! An overriden function to deal with the process of the normal attack action.
	/*!
	\param w a sf::RenderWindow reference argument.
	*/
	void resolve(sf::RenderWindow& w) override;

};

