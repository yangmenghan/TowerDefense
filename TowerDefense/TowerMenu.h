#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <string>
#include "Button.h"
#include "Menu.h"

using namespace std;

class Tile;

class TowerMenu : public Menu
{
private:
	Button sellButton;							//The button to sell the tower in this tile.
	Button upgradeButton;						//The button to upgrade the tower in this tile.
	shared_ptr<Tile> tile;						//The tile which opens the towermenu.
	
	std::string fontAddress;
	sf::Font font;
	sf::Text upGradePrice;
	sf::Text sellPrice;

public:

	//Constructors and destroyers
	TowerMenu::TowerMenu();						//Defauld constructor.

												//Constructor a towermenu in this tile.
	TowerMenu(shared_ptr<Tile>);
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