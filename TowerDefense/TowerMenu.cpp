#include"TowerMenu.h"

TowerMenu::TowerMenu(shared_ptr<Tile> _pTile)
{
	sf::Vector2i tilePosition(_pTile->getPosition());

	Button sellButton(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("Sell"), tilePosition + sf::Vector2i(-TILE_WIDTH, TILE_HEIGHT));
	Button upgradeButton(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), std::string("UpGrade"), tilePosition + sf::Vector2i(TILE_WIDTH, -TILE_HEIGHT));

}

TowerMenu::~TowerMenu(){}

void TowerMenu::draw()
{

}

void TowerMenu::close()
{

}