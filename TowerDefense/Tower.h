#pragma once
#include "Entity.h"
#include "Config.h"
#include "LevelManager.h"
#include "Attack.h"
#include <memory>
//! Basic class for construction of tower
/*!
Inheritted by NormalTower, SlowTower, SunTower, and MoneyTower.
*/
class Tower :
	public Entity
{
public:
	
	//! A constructor by default.
	Tower();
	
	//! A constructor overriden.
	/*! 
	\param mTile A shared pointer pointing a type Tile. This Tile is where we construct the tower. 
	*/
	Tower(shared_ptr<Tile> mTile);
	
	//! A virtual destructor.
	virtual ~Tower();

	//! A getter returning the damage of tower.
	float getDamage();
	
	//! A getter returning the price of tower.
	int getPrice();

	//! A getter returning the level of tower.
	int getLevel();

	//! A getter returning the range of tower.
	float getRange();

	//! A getter returning the income when selling tower.
	int getIncome();

	//! Set the damage of tower.
	/*!
	\param mDamage A float variable.
	*/
	void setDamage(float mDamage);
	
	//! Set the price of tower.
	/*!
	\param mPrice A integer variable.
	*/
	void setPrice(int mPrice);

	//! Set the level of tower.
	/*!
	\param mLevel A int variable [possible values: 1, 2, 3].
	*/
	void setLevel(int mLevel);

	//! Set the range of tower.
	/*!
	\param mRange A float variable.
	*/
	void setRange(float mRange);

	//! Initiale the attribute attack of this tower.
	void setAttack();

	//! Initiale the texture of tower;
	void setTowerTexture();

	//! Initiale the attribute rangeCircle of this tower.
	void setRangeCircle();

	//! Sell this tower.
	void sellTw();

	//! Tower upgrade. The possible levels are 1, 2, 3.
	void upgradeTw();

	//! Tower downgrade. The possible levels are 1, 2, 3.
	void downgradeTw();

	//! A pure virtual function overriden by derived classes.
	/*!
	\param w A sf::RenderWindow reference variable.
	*/
	virtual void doAttack(sf::RenderWindow& w) = 0;

	//! Update current sprite of tower.
	/*!
	\param i An integer variable representing the current number of sprite.
	*/
	void spriteUpdate(int i);

	//! Draw range circle in the win
	/*!
	\param w A sf::RenderWindow reference variable.
	*/
	void showRangeCircle(sf::RenderWindow& w); 

protected:
	//! A protected shared pointer pointing a type Attack.
	shared_ptr<Attack> attack;

	//! A protected float array containing 3-level values of damage.  
	float damage[3];

	//! A protected integer array containing 3-level values of slowAmount.
	int slowAmount[3];

	//! A protected float array containing 3-level values of range. 
	float range[3];
	
	//! A protected integer array containing 3-level values of speed.
	int speed[3];

	//! A protected integer array containing 3-level values of income.
	int income[3];

	//! A protected integer variable representing price of the tower.
	int price;

	//! A protected integer variable representing level of the tower.
	int level;

	//! A protected integer variable representing current sprite number of the tower.
	int currentSprite;

	//! A protected sf::CircleShape variable representing range circle of the tower.
	sf::CircleShape rangeCircle;
	
};

