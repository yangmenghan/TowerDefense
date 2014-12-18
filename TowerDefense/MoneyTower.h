#pragma once
#include "Tower.h"
#include "NormalAttack.h"

//! Derived class from Tower class.
/*!
Inheritted form Tower to generate money.
*/
class MoneyTower :
	public Tower
{
public:
	//! A constructor.
	/*!
	\param mTile A shared pointer pointing a type Tile. This Tile is where we construct the tower.
	*/
	MoneyTower(shared_ptr<Tile> mTile);

	//! A destructor by default.
	~MoneyTower(){};

	//! To generate money under a frequency. 
	void generateMoney();

	//! An interface to call generateMoney().
	/*!
	\param w A sf::RenderWindow reference variable.
	*/
	void doAttack(sf::RenderWindow& w) override;

	//! A redefined funtion to draw the tower and the generated money.
	/*!
	\param w A sf::RenderWindow reference variable.
	*/
	void draw(sf::RenderWindow& w);

	//! To display the generated money of current action.
	void displayGeneratedMoney();
private:
	sf::Text moneyGenerationDisplay;
	sf::Font font;
	int displayTimer;
};

