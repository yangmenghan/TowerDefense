#pragma once
#include <SFML\Graphics.hpp>
#include <Button.h>

class BuildMenu 
{
private: 
	Button basicTwButton;
	Button slowTwButton;
	Button moneyTwButton;
	Button sunTwButton;
public:
	BuildMenu();
	~BuildMenu();
	void draw();
	void close();
	void buyTower();
};