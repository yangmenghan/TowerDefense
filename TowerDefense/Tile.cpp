#include"Tile.h"

Tile::Tile()
{
	position = sf::Vector2f(0, 0);//默认位置为0,0,代表0行0列
	width = TILE_WIDTH;
	height = TILE_HEIGHT;
	cooldown = 0;
	tower = make_shared<Tower>();
}

Tile::Tile(int x, int y)//构造x行y列的Tile
{
	position = sf::Vector2f(x*TILE_WIDTH, y*TILE_HEIGHT);
	width = TILE_WIDTH;
	height = TILE_HEIGHT;
	cooldown = 0;
	tower = make_shared<Tower>();
}

Tile::~Tile(){};

sf::Vector2f Tile::getPosition()
{
	return position;
}

shared_ptr<Tower>  Tile::getTower()
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

void Tile::setTower(shared_ptr<Tower> mTower)
{
	shared_ptr<Tower>tower(mTower);
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
	if (tower)
	{
		return true;
	}
	else
	{
		return false;
	}

}

shared_ptr<BuildMenu> Tile::openBuildMenu()
{
	BuildMenu buildMenu();
	shared_ptr<BuildMenu>pBuildMenu = make_shared<BuildMenu>(buildMenu);
	return pBuildMenu;
}

shared_ptr<TowerMenu> Tile::openTowerMenu()
{
	TowerMenu towerMenu();
	shared_ptr<TowerMenu>pTowerMenu = make_shared<TowerMenu>(towerMenu);
	return pTowerMenu;
}