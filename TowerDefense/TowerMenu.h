#pragma once
#include <SFML\Graphics.hpp>
#include "Button.h"

class TowerMenu
{
private:
	Button sellButton;
	Button upgradeButton;
public:
	//Constructors and destroyers
	TowerMenu();
	~TowerMenu();

	//Getters
	//Setters
	//Functions
	void draw();
	void close();
};