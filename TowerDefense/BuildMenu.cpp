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

BuildMenu::BuildMenu(shared_ptr<Tile> _pTile)
{
	tile = _pTile;

	sf::Vector2i tilePositionPixel(tile->getPositionPixel());

	Button basicTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("NomalTower"), tilePositionPixel + sf::Vector2i(-TILE_WIDTH, -TILE_HEIGHT));
	Button moneyTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("MoneyTower"), tilePositionPixel + sf::Vector2i(-TILE_WIDTH, TILE_HEIGHT));
	Button slowTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("SlowTower"), tilePositionPixel + sf::Vector2i(TILE_WIDTH, -TILE_HEIGHT));
	Button sunTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("SunTower"), tilePositionPixel + sf::Vector2i(TILE_WIDTH, TILE_HEIGHT));
}

BuildMenu::~BuildMenu(){}

//Getters

shared_ptr<Tile> BuildMenu::getTile()
{
	return tile;
}

//Functions

void BuildMenu::buyNomalTw()
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

void BuildMenu::draw()
{

}

void BuildMenu::close()
{

}