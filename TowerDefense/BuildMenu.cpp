#include "BuildMenu.h"
#include "Config.h"
#include "LevelManager.h"
#include "NormalTower.h"
#include "MoneyTower.h"
#include "SlowTower.h"
#include "SunTower.h"
#include "Tower.h"

//Constructors, destructors

BuildMenu::BuildMenu(){}

BuildMenu::BuildMenu(std::string myTextureAdress, sf::Vector2u mySize, sf::Vector2i myPosition, shared_ptr<Tile> pTile) : Menu(myTextureAdress, mySize, myPosition)
{
	

	tile = pTile;

	sf::Vector2i tilePositionPixel(tile->getPositionPixel());


	Button basicTw(BASIC_TOWER_BUTTON_TEXTURE, SMALL_BUTTON_SIZE, sf::Vector2i(2000, 200), 2);
	Button moneyTw(MONEY_TOWER_BUTTON_TEXTURE, SMALL_BUTTON_SIZE, sf::Vector2i(2000, 200), 2);
	Button slowTw(SLOW_TOWER_BUTTON_TEXTURE, SMALL_BUTTON_SIZE, sf::Vector2i(2000, 200), 2);
	Button sunTw(SUN_TOWER_BUTTON_TEXTURE, SMALL_BUTTON_SIZE, sf::Vector2i(2000, 200), 2);
}

BuildMenu::~BuildMenu(){}

//Getters

shared_ptr<Tile> BuildMenu::getTile()
{
	return tile;
}

//Functions

void BuildMenu::buyBasicTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(-NORMAL_TOWER_PRICE);
	auto pNormalTw = make_shared<NormalTower>(tile);
	tile->setTower(pNormalTw);
}

void BuildMenu::buyMoneyTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(-MONEY_TOWER_PRICE);
	auto pMoneyTw = make_shared<MoneyTower>(tile);
	tile->setTower(pMoneyTw);
}

void BuildMenu::buySlowTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(-SLOW_TOWER_PRICE);
	auto pSlowTw = make_shared<SlowTower>(tile);
	tile->setTower(pSlowTw);
}

void BuildMenu::buySunTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(-SUN_TOWER_PRICE);
	auto pSunTw = make_shared<SunTower>(tile);
	tile->setTower(pSunTw);
}

void BuildMenu::resolveEvent(sf::Event event)
{
	if (basicTwButton.checkHover())
	{	
		basicTwButton.resolveEvent(event);
		if (basicTwButton.checkClick())
		{
			buyBasicTw();
		}
	}
	else if (sunTwButton.checkHover())
	{
		sunTwButton.resolveEvent(event);
		if (sunTwButton.checkClick())
		{
			buySunTw();
		}
	}
	else if (slowTwButton.checkHover())
	{
		slowTwButton.resolveEvent(event);
		if (slowTwButton.checkClick())
		{
			buySlowTw();
		}
	}
	else if (moneyTwButton.checkHover())
	{
		moneyTwButton.resolveEvent(event);
		if (moneyTwButton.checkClick())
		{
			buyMoneyTw();
		}
	}
	//field.mouseClick(_event) && (!buildMenu.mouseClick(_event))
	else 
	{
		close();
	}
}

void BuildMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
	basicTwButton.draw(w);
	slowTwButton.draw(w);
	moneyTwButton.draw(w);
	sunTwButton.draw(w);
}

void BuildMenu::close()
{
	//to do.
}