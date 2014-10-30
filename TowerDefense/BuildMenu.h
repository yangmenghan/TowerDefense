#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <string>
#include "Menu.h"
#include "Button.h"
#include "Tile.h"
#include "Tower.h"
#include "NormalTower.h"
#include "MoneyTower.h"
#include "SlowTower.h"
#include "SunTower.h"

class BuildMenu 
	: public Menu
{
private: 
	shared_ptr<Tile> tile;
	Button basicTwButton;
	Button slowTwButton;
	Button moneyTwButton;
	Button sunTwButton;
public:
	//Constructors, destructors
	BuildMenu(shared_ptr<Tile>);
	~BuildMenu();

	//Getters
	shared_ptr<Tile> getTile();

	//Setters

	//Functions
	void buyNomalTw();
	void buySlowTw();
	void buyMoneyTw();
	void buySunTw();

	void draw();
	void close();
};