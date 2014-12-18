#pragma once
#include "Tower.h"
#include "AreaAttack.h"

//! Derived class from Tower class.
/*!
Inheritted form Tower with area attack.
*/
class SunTower :
	public Tower
{
public:

	//! A constructor.
	/*!
	\param mTile A shared pointer pointing a type Tile. This Tile is where we construct the tower.
	*/
	SunTower(shared_ptr<Tile> mTile);

	//! A destructor by default.
	~SunTower(){};

	//! Execute the attack action. An implementation of Tower::doAttack(sf::RenderWindow& w).
	/*!
	\param w A sf::RenderWindow reference variable.
	*/
	void doAttack(sf::RenderWindow& w) override;
};

