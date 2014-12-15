#pragma once
#include "Attack.h"

//! Derived class from Attack class for AreaTowers' attack action.
/*!
Inheritted form Attack and used by SunTower.
*/
class AreaAttack :
	public Attack
{
public:

	//! AreaAttack constructor.
	AreaAttack();

	//! AreaAttack destructor.
	~AreaAttack();

	//! Determine if there is enemy in the range and return un boolean.
	/*!
	\return A boolean. If there is at least an anemy in the range, return true. Else return false.
	*/
	bool hasEnemyInRange();

	//! A redefined funtion returning a vector containing all shared pointers that point to enemies in the attack circle.
	/*!
	\return A vector of shared pointer pointing enemies in the attack circle.
	*/
	vector<shared_ptr<Enemy>> getTarget();
	
	//! An overriden function to deal with the animation of the area attack action.
	/*!
	\param w a sf::RenderWindow reference argument.
	\return void
	*/
	void attackAnimation(sf::RenderWindow& w) override;

	//! An overriden function to deal with the process of the area attack action.
	/*!
	\param w a sf::RenderWindow reference argument.
	*/
	void resolve(sf::RenderWindow& w) override;

private:
	sf::CircleShape attackCircle;
};

