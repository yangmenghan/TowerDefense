#include"Tile.h"

//Constructors and destroyers
Tile::Tile()
{
	position = sf::Vector2i(0, 0);//默认位置为0,0,代表0行0列
	width = TILE_WIDTH;
	height = TILE_HEIGHT;
	cooldown = 0;
	tower = make_shared<Tower>();
}

Tile::Tile(int x, int y)//构造x行y列的Tile
{
	positionPixel = sf::Vector2i(x*TILE_WIDTH, y*TILE_HEIGHT);
	width = TILE_WIDTH;
	height = TILE_HEIGHT;
	cooldown = 0;
	tower = make_shared<Tower>();
}

Tile::~Tile(){}

//Getters
std::vector<Tile*> Tile::getNeighbor(int _range)
{
	std::vector<Tile*> neighborTiles;
	Tile* pNeighber;
	int i, j;
	for (i = position.x - _range; i <= position.x + _range; i++)
	{
		for (j = position.y - _range; j <= position.y + _range; j++)
		{
			if (i >= 0 && i < TILE_NUM_VER && j >= 0 && j <= TILE_NUM_HOR)
			{
				pNeighber = field.getTile(sf::Vector2i(i,j));  //need to construct un instance field
				neighborTiles.push_back(pNeighber);
			}
		}
	}
	return neighborTiles;

}
sf::Vector2i Tile::getPosition()
{
	return position;
}

sf::Vector2i Tile::getPositionPixel()
{
	return positionPixel;
}

shared_ptr<Tower>  Tile::getTower()
{
	return tower;
}

int Tile::getCooldowm()
{
	return cooldown;
}

//Setters
void Tile::setPosition(sf::Vector2i mPosition)
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

//Functions
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