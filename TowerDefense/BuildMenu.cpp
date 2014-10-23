#include"BuildMenu.h"

BuildMenu::BuildMenu(shared_ptr<Tile> _pTile)
{
	
	sf::Vector2i tilePosition(_pTile->getPosition());

	Button basicTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("BasicTower"), tilePosition + sf::Vector2i(-TILE_WIDTH , -TILE_HEIGHT ));
	Button moneyTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("MoneyTower"), tilePosition + sf::Vector2i(-TILE_WIDTH, TILE_HEIGHT));
	Button slowTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("SlowTower"), tilePosition + sf::Vector2i(TILE_WIDTH, -TILE_HEIGHT));
	Button sunTw(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("SunTower"), tilePosition + sf::Vector2i(TILE_WIDTH, TILE_HEIGHT));
	
}

BuildMenu::~BuildMenu(){};

void BuildMenu::buyBasicTw()
{
	Player::manageMoney();
}

void BuildMenu::buyMoneyTw()
{

}

void BuildMenu::buySlowTw()
{

}

void BuildMenu::buySunTw()
{

}

void BuildMenu::draw()
{

}

void BuildMenu::close()
{

}