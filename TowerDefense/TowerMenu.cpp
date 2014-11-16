#include"TowerMenu.h"
#include "Config.h"

//Constructors and destroyers

TowerMenu::TowerMenu(){}

TowerMenu::TowerMenu(shared_ptr<Tile> _pTile)
{
	tile = _pTile;

	sf::Vector2i tilePositionPixel(tile->getPositionPixel());

	Button sellButton(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("Sell"), tilePositionPixel + sf::Vector2i(-TILE_WIDTH, TILE_HEIGHT));
	Button upgradeButton(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("UpGrade"), tilePositionPixel + sf::Vector2i(TILE_WIDTH, -TILE_HEIGHT));
}

TowerMenu::~TowerMenu(){}

//Getters

shared_ptr<Tile> TowerMenu::getTile()
{
	return tile;
}

//Functions

void TowerMenu::draw()
{

}

void TowerMenu::close()
{

}