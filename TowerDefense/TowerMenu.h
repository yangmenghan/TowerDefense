#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <string>
#include "Tile.h"
#include "Button.h"

class TowerMenu
{
private:
	Button sellButton;
	Button upgradeButton;
public:
	//Constructors and destroyers
	TowerMenu(shared_ptr<Tile>);
	~TowerMenu();

	//Getters
	//Setters
	//Functions
	void draw();
	void close();
};