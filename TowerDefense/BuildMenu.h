#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <string>
#include "Menu.h"
#include "Button.h"

using namespace std;

class Tile;

class BuildMenu 
	: public Menu
{
private: 
	shared_ptr<Tile> tile;//The tile which opens the buildmenu.
	Button basicTwButton;//The button for building a basic tower in the tile.
	Button slowTwButton;//The button for building a slow tower in the tile.
	Button moneyTwButton;//The button for building a money tower in the tile.
	Button sunTwButton;//The button for building a sun tower in the tile.
public:
	//Constructors, destructors
	BuildMenu();//Default constructor.
	BuildMenu(shared_ptr<Tile>);//Constructor a buildmenu in this tile. 
	~BuildMenu();//Destructor.

	//Getters
	shared_ptr<Tile> getTile();//Get the tile where build the tower.

	//Setters

	//Functions
	void buyNomalTw();//Buy and build a normal tower.
	void buySlowTw();//Buy and build a slow tower.
	void buyMoneyTw();//Buy and build a money tower.
	void buySunTw(); // Buy and build a sun tower.

	void draw();//Draw the menu.
	void close();//Close the menu.
};