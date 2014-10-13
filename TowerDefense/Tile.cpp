#include"Tile.h"

Tile::Tile(){
	position = sf::Vector2f(0, 0);
	width = TILE_WIDTH;
	height = TILE_HEIGHT;
	cooldown = 0;
	tower = NULL;
}

Tile::~Tile(){};

sf::Vector2f Tile::getPosition()
{
	return position;
}

Tower* Tile::getTower()
{
	return tower;
}

int Tile::getCooldowm()
{
	return cooldown;
}

void Tile::setPosition(sf::Vector2f mPosition)
{
	mPosition = mPosition;
}

void Tile::setTower(Tower* mTower)
{
	tower = mTower;
}

void Tile::setCooldown(int mCooldown)
{
	cooldown = mCooldown;
}

bool Tile::isPolluted()
{
	if (cooldown != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Tile::hasTower()
{
	if (tower != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

}

BuildMenu* Tile::openBuildMenu()
{
	BuildMenu buildMenu;
	BuildMenu* pBuildMenu;
	pBuildMenu = &buildMenu;
	return pBuildMenu;
}

TowerMenu* Tile::openTowerMenu()
{
	TowerMenu towerMenu;
	TowerMenu* ptowerMenu;
	ptowerMenu = &towerMenu;
	return ptowerMenu;
}