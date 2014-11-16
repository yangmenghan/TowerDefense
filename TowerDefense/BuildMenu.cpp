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

BuildMenu::BuildMenu(std::string myTextureAdress, sf::Vector2u mySize, sf::Vector2i myPosition,shared_ptr<Tile> pTile)
{
	Menu(myTextureAdress, mySize, myPosition);

	tile = pTile;

	sf::Vector2i tilePositionPixel(tile->getPositionPixel());


	Button basicTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), BASIC_TOWER_BUTTON_TEXTURE, tilePositionPixel + sf::Vector2i(-TILE_WIDTH, -TILE_HEIGHT));
	Button moneyTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), MONEY_TOWER_BUTTON_TEXTURE, tilePositionPixel + sf::Vector2i(-TILE_WIDTH, TILE_HEIGHT));
	Button slowTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), SLOW_TOWER_BUTTON_TEXTURE, tilePositionPixel + sf::Vector2i(TILE_WIDTH, -TILE_HEIGHT));
	Button sunTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), SUN_TOWER_BUTTON_TEXTURE, tilePositionPixel + sf::Vector2i(TILE_WIDTH, TILE_HEIGHT));
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
	NormalTower normalTw();
	auto pNormalTw = make_shared<NormalTower>(normalTw);
	tile.operator*().setTower(pNormalTw);
}

void BuildMenu::buyMoneyTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(-MONEY_TOWER_PRICE);
	MoneyTower moneyTw();
	auto pMoneyTw = make_shared<MoneyTower>(moneyTw);
	tile.operator*().setTower(pMoneyTw);
}

void BuildMenu::buySlowTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(-SLOW_TOWER_PRICE);
	SlowTower slowTw();
	auto pSlowTw = make_shared<SlowTower>(slowTw);
	tile.operator*().setTower(pSlowTw);
}

void BuildMenu::buySunTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(-SUN_TOWER_PRICE);
	SunTower sunTw();
	auto pSunTw = make_shared<SunTower>(sunTw);
	tile.operator*().setTower(pSunTw);
}

void BuildMenu::resolveEvent(sf::Event _event)
{
	if (basicTwButton.mouseClick(_event))
	{
		buyBasicTw();
	}
	if (slowTwButton.mouseClick(_event))
	{
		buySlowTw();
	}
	if (sunTwButton.mouseClick(_event))
	{
		buySunTw();
	}
	if (moneyTwButton.mouseClick(_event))
	{
		buyMoneyTw();
	}
	if (true)///todo 
		//field.mouseClick(_event) && (!buildMenu.mouseClick(_event))
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