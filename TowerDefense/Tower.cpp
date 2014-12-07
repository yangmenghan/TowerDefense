#include "Tower.h"
#include "Player.h"
#include "LevelManager.h"
#include "NormalAttack.h"

Tower::Tower(shared_ptr<Tile> mTile)
{
	level = 1;
	currentSprite = level - 1;
	tile = mTile;
	size = sf::Vector2i(TILE_WIDTH, TILE_HEIGHT);
	attack = make_shared<NormalAttack>();
	attack->setCenter(tile->getPosition());

	speed = TOWER_SPEED;
}


Tower::~Tower()
{
}
/*
Getters and Setters
*/
float Tower::getDamage()
{
	return damage[level - 1];
}

int Tower::getPrice()
{
	return price;
}

int Tower::getLevel()
{
	return level;
}

float Tower::getRange()
{
	return range[level - 1];
}

void Tower::setDamage(float mDamage)
{
	damage[level - 1] = mDamage;
}

void Tower::setPrice(int mPrice)
{
	price = mPrice;
}

void Tower::setLevel(int mLevel)
{
	level = mLevel;
}

void Tower::setRange(float mRange)
{
	range[level - 1] = mRange;
}

void Tower::spriteUpdate(int i)
{
	currentSprite = i;
}

/*
Upgrade the level of tower and set its new parameters
*/
void Tower::upgradeTw()
{
	if (level < 3)
	{
		level++;
		speed -= 5;
		currentSprite = level - 1;

		attack->setDamage(damage[level - 1]);
		attack->setSlowAmount(damage[level - 1]);
		attack->setSpeed(speed);
		attack->setRange(range[level - 1]);

		timer = speed;

		spriteUpdate(currentSprite);
	}
}
/*
Downgrade the level of tower and set its new parameters
*/
void Tower::downgradeTw()
{
	if (level > 0)
	{
		level--;
		
		if (level != 0)
		{
			speed += 5;
			currentSprite = level - 1;

			attack->setDamage(damage[level - 1]);
			attack->setSlowAmount(damage[level - 1]);
			attack->setSpeed(speed);
			attack->setRange(range[level - 1]);

			timer = speed;

			spriteUpdate(currentSprite);
		}
	}
	if (level == 0)
	{
		LevelManager::getLevelManager()->removeTower(shared_ptr<Tower>(this));
		tile->setTower(NULL);
		//this->~Tower();//Delete this tower
	}
		
}

/*
Sell this tower and
*/
void Tower::sellTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(income[level - 1]);
}


