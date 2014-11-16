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
	Button sellButton;							//The button to sell the tower in this tile.
	Button upgradeButton;						//The button to upgrade the tower in this tile.
	shared_ptr<Tile> tile;						//The tile which opens the towermenu.

public:

	//Constructors and destroyers
	TowerMenu::TowerMenu();						//Defauld constructor.
	TowerMenu(std::string, sf::Vector2u, sf::Vector2i, shared_ptr<Tile>);
												//Constructor a towermenu in this tile.
	~TowerMenu();								//Destructor.

	//Getters
	shared_ptr<Tile> getTile();					//Get the tile which opens the towermenu.

	//Setters

	//Functions
	void resolveEvent(sf::Event);
	void sellTower();
	void draw(sf::RenderWindow&);				//Draw the menu.
	void close();								//Close the menu.
};