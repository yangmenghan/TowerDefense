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

int Tile::getCooldown()
{
	return cooldown;
}

std::vector<shared_ptr<Tile>> Tile::getNeighbor(int _range)
{
	std::vector<shared_ptr<Tile>> neighborTiles;
	shared_ptr<Tile> pNeighber;

	for (int i = position.x - _range; i <= position.x + _range; i++)
	{
		for (int j = position.y - _range; j <= position.y + _range; j++)
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
void Tile::setCooldown()
{
	cooldown = TILE_COOLDOWN;
	currentSprite = 2;
	spriteUpdate(currentSprite);
}

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
			currentSprite = 1;
			spriteUpdate(currentSprite);
			if (hasTower())
				tower->showRangeCircle(w);
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
	else if (!hasEnemy())
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
	return (cooldown != 0);
}

bool Tile::hasTower()
{
	return hasTw;
}

shared_ptr<BuildMenu> Tile::openBuildMenu()
{
	
		auto buildMenuptr = make_shared<BuildMenu>(shared_from_this());
		MenuManager::getMenuManager()->addMenu(buildMenuptr);
		MenuManager::getMenuManager()->setExistBTMenu(true);
		return buildMenuptr;

}

bool Tile::hasEnemy(){
	LevelManager* levelManager = LevelManager::getLevelManager();
	vector<shared_ptr<Enemy>> enemies;
	enemies = levelManager->getEnemies();	//get the list of enemies
	for (int i = 0; i < enemies.size(); i++)
	{
		shared_ptr<Enemy> enemy = enemies[i];
		if (position == (*(*enemy).getTile()).getPosition())
			return true;
	}
	return false;
}

shared_ptr<TowerMenu> Tile::openTowerMenu()
{
	auto TowerMenuptr = make_shared<TowerMenu>(shared_from_this());
	MenuManager::getMenuManager()->addMenu(TowerMenuptr);
	MenuManager::getMenuManager()->setExistBTMenu(true);
	return TowerMenuptr;

}

void Tile::draw(sf::RenderWindow& w)
{
	if (isPolluted()){
		cooldown--;
		if (cooldown == 0)
		{
			currentSprite = 0;
			spriteUpdate(currentSprite);
		}
	}
		
	if (hasTower() && isHovered)
	{
		getTower()->showRangeCircle(w);
	}

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