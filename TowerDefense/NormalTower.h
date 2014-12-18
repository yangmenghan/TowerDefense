#pragma once
#include "Tower.h"
#include "NormalAttack.h"

//! Derived class from Tower class.
/*!
Inheritted form Tower with normal attack.
*/
class NormalTower :
	public Tower
{
public:
	//! A constructor.
	/*!
	\param mTile A shared pointer pointing a type Tile. This Tile is where we construct the tower.
	*/
	NormalTower(shared_ptr<Tile> mTile);

	//! A destructor by default.
	~NormalTower(){};

	//! A redefined function. Draw the tower in a render window
	/*!
	\param w A sf::RenderWindow reference variable.
	*/
	void draw(sf::RenderWindow &w);
	
	//! Execute the attack action. An implementation of Tower::doAttack(sf::RenderWindow& w).
	/*!
	\param w A sf::RenderWindow reference variable.
	*/
	void doAttack(sf::RenderWindow& w)override;
};

