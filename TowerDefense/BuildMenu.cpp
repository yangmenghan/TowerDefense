#include"BuildMenu.h"

BuildMenu::BuildMenu(shared_ptr<Tile> _pTile)
{
	Button basicTw( sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("BasicTower"), _pTile->getPosition());
	
}

BuildMenu::~BuildMenu(){};

void BuildMenu::buyBasicTw()
{

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