#include"TowerMenu.h"
#include "Config.h"
#include "Tile.h"
#include "Tower.h"

//Constructors and destroyers

TowerMenu::TowerMenu(){}

TowerMenu::TowerMenu(std::string myTextureAdress, sf::Vector2u mySize, sf::Vector2i myPosition, shared_ptr<Tile> pTile) :Menu(myTextureAdress, mySize, myPosition)
{

	tile = pTile;

	sf::Vector2i tilePositionPixel(tile->getPositionPixel());

	Button sellButton(SELL_BUTTON_TEXTURE, sf::Vector2i(BUTTON_WIDTH, BUTTON_HEIGHT), tilePositionPixel + sf::Vector2i(-TILE_WIDTH, TILE_HEIGHT),2);
	Button upgradeButton(UPGRADE_BUTTON_TEXTURE, sf::Vector2i(BUTTON_WIDTH, BUTTON_HEIGHT), tilePositionPixel + sf::Vector2i(TILE_WIDTH, -TILE_HEIGHT),2);
}

TowerMenu::~TowerMenu(){}

//Getters

shared_ptr<Tile> TowerMenu::getTile()
{
	return tile;
}

//Functions

void TowerMenu::resolveEvent(sf::Event _event)
{
	if (sellButton.mouseClick(_event))
	{
		tile->getTower()->sellTw();
	}
	if (upgradeButton.mouseClick(_event))
	{
		tile->getTower()->upgradeTw();
	}
}

void TowerMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
	sellButton.draw(w);
	upgradeButton.draw(w);
}

void TowerMenu::close()
{
	//to do  with menumanager
}