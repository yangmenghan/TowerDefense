#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
//! Basic class for towers' attack action.
/*! 
Inheritted by NormalAttack, SlowAttack and AreaAttack to realise attack action respectively.
*/
class Attack
{

public:
	//! A constructor by default.
	Attack();

	//! A destructor by default.
	~Attack();

	//! A getter returning the float value of the attribute damage.
	/*!
	\return The float value of damage.
	*/
	float getDamage();
	
	//! A getter returning the float value of the attribute slowAmount.
	/*!
	\return The float value of slowAmount.
	*/
	float getSlowAmount();

	//! Set the value of the attribute damage
	/*!
	\param mDamage a float argument.
	\return void.
	*/
	void setDamage(float mDamage);
	
	//! Set the value of the attribute slowAmount
	/*!
	\param mSlowAmount a float argument.
	\return void.
	*/
	void setSlowAmount(float mSlowAmount);
	
	//! Set the value of attribute center.
	/*!
	\param mCenter a sf::Vector2i argument.
	\return void.
	*/
	void setCenter(sf::Vector2i mCenter);
	
	//! Set the value of attribute range.
	/*!
	\param mCenter a float argument.
	\return void.
	*/
	void setRange(float mRange);

	//! Set the value of attribute speed.
	/*!
	\param mSpeed an integer argument.
	\return void.
	*/
	void setSpeed(int mSpeed);
	
	//! Set the value of attribute timer.
	/*!
	\param mTimer an integer argument.
	\return void.
	*/
	void setTimer(int mTimer);

	//! Get a target in the list of enemies in the field to attack. The target will be the enemy who is closest to the end. 
	/*!
	\return a shared pointer who point the target enemy.
	*/
	shared_ptr<Enemy> getTarget();

	//! Get the center of this attack action.
	/*!
	\return A sf::Vector2i value representing the center of this attack action.
	*/
	sf::Vector2i getCenter();

	//! Compute the angle of attact ray that points to the target from the attack center. And then set rotation of the attribute attackRay.
	/*!
	\param target the target enemy.
	\return void
	*/
	void setAttackRayAngle(shared_ptr<Enemy> target);
	
	//! A pure virtual function.
	/*!
	\param w A sf::RenderWindow reference argument.
	\return void
	\sa NormalAttack::attackAnimation(sf::RenderWindow& w), SlowAttack::attackAnimation(sf::RenderWindow& w) and AreaAttack::attackAnimation(sf::RenderWindow& w)
	*/
	void virtual attackAnimation(sf::RenderWindow& w) = 0;

	//! A pure virtual function.
	/*!
	\param w A sf::RenderWindow reference argument.
	\return void
	\sa NormalAttack::resolve(sf::RenderWindow& w), SlowAttack::resolve(sf::RenderWindow& w) and AreaAttack::resolve(sf::RenderWindow& w)
	*/
	void virtual resolve(sf::RenderWindow& w) = 0;

	sf::RectangleShape getAttackRay();

protected:
	//! A protected float variable representing slowing effect of the attack action, especially for the slowAttack.
	float slowAmount;

	//! A protected float variable representing the damage of the attack action.
	float damage;

	//! A protected float variable representing the range of the attack action.
	float range;

	//! A protected sf::Vector2i variable representing the center of the attack action.
	sf::Vector2i center;

	//! A protected integer variable controlling the frequency of the attack, using with the attribute speed.
	int timer;

	//! A protected integer variable representing the frequency of the attack, using with the attribute timer.
	int speed;

	//! A protected float variable representing the distance between the target enemy and the attack center.
	float targetDistance;


	//! A protected sf::RectangleShape variable representing a line that ponits to the target enemy from the attack center.
	sf::RectangleShape attackRay;
};

