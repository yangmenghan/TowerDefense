#include "Tile.h"
#include "Config.h"
#include "LevelManager.h"
#include "NormalTower.h"


//Constructors and destroyers
Tile::Tile()
{
	position = sf::Vector2i(0, 0);//(row,collon)=(0.0)
	width = TILE_WIDTH;
	height = TILE_HEIGHT;
	cooldown = 0;
	tower = NULL;
	isHovered = false;
	currentSprite = 0;
	if (!texture.loadFromFile(TILE_SPRITE[currentSprite]))
	{
		// TODO erreur...
	}
	sprite.setTexture(texture);
	sf::FloatRect bounding(positionPixel.x + 50, positionPixel.y + 50, TILE_WIDTH, TILE_HEIGHT);
	boundingBox = sprite.getGlobalBounds();
}

Tile::Tile(int x, int y)//(row,collone)=(x,y)
{
	positionPixel = sf::Vector2i(x*TILE_WIDTH, y*TILE_HEIGHT);
	position = sf::Vector2i(x, y);
	width = TILE_WIDTH;
	height = TILE_HEIGHT;
	cooldown = 0;
	tower = NULL;
	isHovered = false;	
	currentSprite = 0;
	if (!texture.loadFromFile(TILE_SPRITE[currentSprite]))
	{
		// TODO erreur...
	}
	sprite.setTexture(texture);	
	sf::FloatRect bounding(positionPixel.x + 50, positionPixel.y + 50, TILE_WIDTH, TILE_HEIGHT);
	boundingBox = bounding;
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

bool Tile::mouseHover(sf::RenderWindow& w)
{
	sf::Vector2f mousePosition((float)sf::Mouse::getPosition(w).x, (float)sf::Mouse::getPosition(w).y);

	if (boundingBox.contains(mousePosition))
	{
		isHovered = true;
		spriteUpdate(1);
	}
	else
	{
		isHovered = false;
		spriteUpdate(0);
	}
	return isHovered;
}

bool Tile::mouseClicking(sf::Event event, sf::RenderWindow& w)
{
	if (mouseHover(w))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			return true;
			//updatesprite
			spriteUpdate(1);
		}
	}
	return false;
}

bool Tile::mouseClick(sf::Event event, sf::RenderWindow& w)
{
	if (mouseClicking(event,w))
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			return true;
			//updatesprite
			spriteUpdate(1);
		}
	}
	return false;
}

void Tile::resolveEvent(sf::Event event, sf::RenderWindow& w)
{
	
	if (!isPolluted())
	{
		if (mouseHover(w))
		{
			if (mouseClick(event,w))
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

	sprite.setPosition(sf::Vector2f(float(positionPixel.x + TILE_WIDTH), float(positionPixel.y+TILE_HEIGHT)));
	
	mouseHover(w);
	w.draw(sprite);
}

void Tile::spriteUpdate(int i)
{
	currentSprite = i;
	texture.loadFromFile(TILE_SPRITE[currentSprite]);
}