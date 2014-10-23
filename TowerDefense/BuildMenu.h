#pragma once
#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Button.h"
#include "Tile.h"
#include <memory>
#include <string>


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