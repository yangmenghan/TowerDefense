#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <string>
#include "Tile.h"
#include "Button.h"

class TowerMenu 
	: public Menu
{
private:
	Button sellButton;
	Button upgradeButton;
	shared_ptr<Tile> tile;
public:

	//Constructors and destroyers
	TowerMenu::TowerMenu(){};
	TowerMenu(shared_ptr<Tile>);
	~TowerMenu();

	//Getters
	shared_ptr<Tile> getTile();

	//Setters
	//Functions
	void draw();
	void close();
};