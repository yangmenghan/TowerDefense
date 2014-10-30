#include"BuildMenu.h"

//Constructors, destructors
BuildMenu::BuildMenu(shared_ptr<Tile> _pTile)
{
	tile = _pTile;

	sf::Vector2i tilePosition(tile->getPosition());

	Button basicTw(w, sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("NomalTower"), tilePosition + sf::Vector2i(-TILE_WIDTH, -TILE_HEIGHT));
	Button moneyTw(w, sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("MoneyTower"), tilePosition + sf::Vector2i(-TILE_WIDTH, TILE_HEIGHT));
	Button slowTw(w, sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("SlowTower"), tilePosition + sf::Vector2i(TILE_WIDTH, -TILE_HEIGHT));
	Button sunTw(w, sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("SunTower"), tilePosition + sf::Vector2i(TILE_WIDTH, TILE_HEIGHT));
}

BuildMenu::~BuildMenu(){};

//Getters

shared_ptr<Tile> BuildMenu::getTile()
{
	return tile;
}

//Functions

void BuildMenu::buyNomalTw()
{
	LevelManager::getLevelManager().getPlayer().manageMoney(-NORMAL_TOWER_PRICE);
	NormalTower normalTw();
	auto pNormalTw = make_shared<NormalTower>(normalTw);
	tile.operator*().setTower(pNormalTw);
}

void BuildMenu::buyMoneyTw()
{
	LevelManager::getLevelManager().getPlayer().manageMoney(-MONEY_TOWER_PRICE);
	MoneyTower moneyTw();
	auto pMoneyTw = make_shared<MoneyTower>(moneyTw);
	tile.operator*().setTower(pMoneyTw);
}

void BuildMenu::buySlowTw()
{
	LevelManager::getLevelManager().getPlayer().manageMoney(-SLOW_TOWER_PRICE);
	SlowTower slowTw();
	auto pSlowTw = make_shared<SlowTower>(slowTw);
	tile.operator*().setTower(pSlowTw);
}

void BuildMenu::buySunTw()
{
	LevelManager::getLevelManager().getPlayer().manageMoney(-SUN_TOWER_PRICE);
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