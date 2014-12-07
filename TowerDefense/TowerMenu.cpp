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

	sellButton = Button(SELL_BUTTON_TEXTURE, SMALL_BUTTON_SIZE, tilePositionPixel + sf::Vector2i(-BUTTON_WIDTH, 0), 1);
	upgradeButton = Button(UPGRADE_BUTTON_TEXTURE, SMALL_BUTTON_SIZE, tilePositionPixel + sf::Vector2i(BUTTON_WIDTH, 0), 1);
}

TowerMenu::TowerMenu(shared_ptr<Tile> pTile)
{
	tile = pTile;

	sf::Vector2i tilePositionPixel(tile->getPositionPixel());

	sellButton = Button(SELL_BUTTON_TEXTURE, SMALL_BUTTON_SIZE, tilePositionPixel + sf::Vector2i(-BUTTON_WIDTH, 0), 1);
	upgradeButton = Button(UPGRADE_BUTTON_TEXTURE, SMALL_BUTTON_SIZE, tilePositionPixel + sf::Vector2i(BUTTON_WIDTH, 0), 1);
}

TowerMenu::~TowerMenu(){}

//Getters

shared_ptr<Tile> TowerMenu::getTile()
{
	return tile;
}

//Functions

void TowerMenu::resolveEvent(sf::Event event)
{
	if (sellButton.checkHover())
	{
		sellButton.resolveEvent(event);
		if (sellButton.checkClick())
		{
			tile->getTower()->sellTw();
			close();
		}		
	}
	else if (upgradeButton.checkHover())
	{
		upgradeButton.resolveEvent(event);
		if (upgradeButton.checkClick())
		{
			tile->getTower()->upgradeTw();
			close();
		}
	}
	else 
	{
		close();
	}
}

void TowerMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);

	sellButton.mouseHover(w);
	upgradeButton.mouseHover(w);

	sellButton.draw(w);
	upgradeButton.draw(w);

	LevelManager::getLevelManager()->setSpeed(0);
}

void TowerMenu::close()
{
	MenuManager::getMenuManager()->popMenu();
	LevelManager::getLevelManager()->setSpeed(1);
}