#include "Tile.h"
#include "Config.h"
#include "LevelManager.h"
#include "NormalTower.h"

//Constructors and destroyers
Tile::Tile()
{
	position = sf::Vector2i(0, 0);//默认位置为0,0,代表0行0列
	width = TILE_WIDTH;
	height = TILE_HEIGHT;
	cooldown = 0;
	tower = NULL;
	boundingBox = sprite.getGlobalBounds();
	if (!texture.loadFromFile(TILE_SPRITE))
	{
		// TODO erreur...
	}
}

Tile::Tile(int x, int y)//构造x行y列的Tile
{
	positionPixel = sf::Vector2i(x*TILE_WIDTH, y*TILE_HEIGHT);
	position = sf::Vector2i(x*TILE_WIDTH, y*TILE_HEIGHT);
	width = TILE_WIDTH;
	height = TILE_HEIGHT;
	cooldown = 0;
	tower = NULL;
	boundingBox = sprite.getGlobalBounds();
	if (!texture.loadFromFile(TILE_SPRITE))
	{
		// TODO erreur...
	}
}

Tile::~Tile(){}

//Getters

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

std::vector<shared_ptr<Tile>> Tile::getNeighbor(int _range)
{
	std::vector<shared_ptr<Tile>> neighborTiles;
	shared_ptr<Tile> pNeighber;
	int i, j;
	for (i = position.x - _range; i <= position.x + _range; i++)
	{
		for (j = position.y - _range; j <= position.y + _range; j++)
		{
			if (i >= 0 && i < TILE_NUM_VER && j >= 0 && j <= TILE_NUM_HOR)
			{
				pNeighber = LevelManager::getLevelManager()->getField().getTile(sf::Vector2i(i, j)); 
				neighborTiles.push_back(pNeighber);
			}
		}
	}
	return neighborTiles;

}

sf::Sprite Tile::getSprite()
{
	return sprite;
}

//Setters
void Tile::setPosition(sf::Vector2i myPosition)
{
	myPosition = myPosition;
}

void Tile::setTower(shared_ptr<Tower> myTower)
{
	shared_ptr<Tower>tower(myTower);
}

void Tile::setCooldown(int myCooldown)
{
	cooldown = myCooldown;
}

void Tile::setSprite(sf::Sprite mySprite)
{
	sprite = mySprite;
}

//Functions

bool Tile::mouseHover()
{
	bool isHovering = false;
	sf::Vector2f mousePosition((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y);

	if (boundingBox.contains(mousePosition))
	{
		isHovering = true;
		//updatesprite
	}
	else
	{
		isHovering = false;
		//updatesprite
	}

	return isHovering;
}

bool Tile::mouseClicking(sf::Event event)
{
	if (mouseHover())
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			return true;
			//updatesprite
		}
	}
	return false;
}

bool Tile::mouseClick(sf::Event event)
{
	if (mouseClicking(event))
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			return true;
			//updatesprite
		}
	}
	return false;
}

void Tile::resolveEvent(sf::Event event)
{
	if (!isPolluted())
	{
		if (mouseHover())
		{
			if (mouseClick(event))
			{
				if (hasTower())
				{
					openTowerMenu();
				}
				else
				{
					openBuildMenu();
				}
			}
		}
	}	
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
	return make_shared<BuildMenu>();
}

shared_ptr<TowerMenu> Tile::openTowerMenu()
{
	return make_shared<TowerMenu>();

}

void Tile::draw(sf::RenderWindow& w)
{
	sprite.setTexture(texture);

	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(width, height)));

	sprite.setPosition(sf::Vector2f(float(position.x + TILE_WIDTH), float(position.y+TILE_HEIGHT)));
	w.draw(sprite);
}