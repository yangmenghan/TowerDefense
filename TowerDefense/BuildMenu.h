#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <string>
#include "Menu.h"
#include "Button.h"
#include "Tile.h"

class BuildMenu : public Menu
{
private: 
	Button basicTwButton;
	Button slowTwButton;
	Button moneyTwButton;
	Button sunTwButton;
public:
	//Constructors, destructors
	BuildMenu(shared_ptr<Tile>);
	~BuildMenu();

	//Getters
	
	//Setters

	//Functions
	void buyBasicTw();
	void buySlowTw();
	void buyMoneyTw();
	void buySunTw();

	void draw();
	void close();
};