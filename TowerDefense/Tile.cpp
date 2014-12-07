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
	isClicked = false;
	isClicking = false;
	hasTw = false;
	currentSprite = 0;
	if (!texture.loadFromFile(TILE_SPRITE))
	{
		// TODO erreur...
	}
	sf::FloatRect bounding(positionPixel.x + 50, positionPixel.y + 50, TILE_WIDTH, TILE_HEIGHT);
	boundingBox = sf::IntRect(positionPixel, sf::Vector2i(width, height));
}

Tile::Tile(int x, int y)//(row,collone)=(x,y)
{
	positionPixel = sf::Vector2i(x*TILE_WIDTH + 50, y*TILE_HEIGHT + 50);
	position = sf::Vector2i(x, y);
	width = TILE_WIDTH;
	height = TILE_HEIGHT;
	cooldown = 0;
	tower = NULL;
	isHovered = false;	
	isClicked = false;
	isClicking = false;
	hasTw = false;
	currentSprite = 0;
	if (!texture.loadFromFile(TILE_SPRITE))
	{
		// TODO erreur...
	}
	sprite.setTexture(texture);	


	sf::IntRect bounding(positionPixel.x + 50, positionPixel.y + 50, TILE_WIDTH, TILE_HEIGHT);//Board size = 50 ?

	boundingBox = sf::IntRect(positionPixel, sf::Vector2i(width, height));

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
	tower = myTower;
	if (tower != NULL)
	{
		hasTw = true;
	}else 
	{
		hasTw = false;
	}
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
bool Tile::checkHover()
{
	return isHovered;
}

bool Tile::checkClick()
{
	return isClicked;
}

void Tile::mouseHover(sf::RenderWindow& w)
{
	if (boundingBox.contains(sf::Mouse::getPosition(w)))
	{
		if (currentSprite == 0)
		{
			currentSprite == 1;
			spriteUpdate(currentSprite);			
		}
		isHovered = true;
	}
	else
	{
		if (currentSprite == 1)
		{
			currentSprite = 0;
			spriteUpdate(currentSprite);
		}
		isHovered = false;
	}
}

void Tile::resolveEvent(sf::Event event)
{
	spriteUpdate(1);
	if (isPolluted())
	{
		currentSprite = 2;
		spriteUpdate(currentSprite);
	}
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			isClicking = true;
			if (currentSprite == 0)
			{
				currentSprite = 1;
				spriteUpdate(currentSprite);
			}
			
			
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			isClicked = true;

			if (currentSprite == 0)
			{
				currentSprite = 1;
				spriteUpdate(currentSprite);
			}

			if (hasTower())
			{
				openTowerMenu();
			}
			else
			{
				hasTw = true;
				if (LevelManager::getLevelManager()->getField().tryCross(LevelManager::getLevelManager()->getField().getTile(NUM_START_TILE), LevelManager::getLevelManager()->getField().getTile(NUM_END_TILE)))
				{
					openBuildMenu();
				}
				hasTw = false;
			}
		}
	}
	
}

bool Tile::isPolluted()
{
	if (cooldown != 0)
	{
		spriteUpdate(2);
		return true;
	}
	else
	{
		return false;
	}
}

bool Tile::hasTower()
{
	return hasTw;

	/*if (tower != NULL)
	{
		if (tower->getTile()->position == position){
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
	*/
}

shared_ptr<BuildMenu> Tile::openBuildMenu()
{
	auto buildMenuptr = make_shared<BuildMenu>(shared_ptr<Tile>(this));
	MenuManager::getMenuManager()->addMenu(buildMenuptr);
	return buildMenuptr;
}

shared_ptr<TowerMenu> Tile::openTowerMenu()
{
	return make_shared<TowerMenu>();

}

void Tile::draw(sf::RenderWindow& w)
{
	sprite.setTexture(texture);
	sf::Vector2i spriteInit(0, currentSprite*height);
	sprite.setTextureRect(sf::IntRect(spriteInit, sf::Vector2i(width, height)));

	sprite.setPosition(sf::Vector2f(float(positionPixel.x), float(positionPixel.y)));
	mouseHover(w);
	w.draw(sprite);
}

void Tile::spriteUpdate(int i)
{
	currentSprite = i;
}