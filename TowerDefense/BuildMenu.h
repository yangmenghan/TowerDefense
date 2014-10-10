#pragma once
#include <SFML\Graphics.hpp>

class BuildMenu 
{
private: 
	button basicTwButton;
	button slowTwButton;
	button moneyTwButton;
	button sunTwButton;
public:
	BuildMenu();
	~BuildMenu();
	void draw();
	void close();
	void buyTower();
};