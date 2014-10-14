#pragma once
#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Button.h"


class BuildMenu : public Menu
{
private: 
	Button basicTwButton;
	Button slowTwButton;
	Button moneyTwButton;
	Button sunTwButton;
public:
//Constructors, destructors
	BuildMenu();
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