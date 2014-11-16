#include "Tower.h"
#include "Player.h"
#include "LevelManager.h"

Tower::Tower(Tile mTile)
{
	this->tile = mTile;
	this->attack.setRange(range);
	this->attack.setCenter(tile.getPosition());
}


Tower::~Tower()
{
}

float Tower::getDamage()
{
	return damage;
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
	return range;
}

void Tower::setDamage(float mDamage)
{
	damage = mDamage;
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
	range = mRange;
}




void Tower::upgradeTw()
{
	if (level < 3)
	{
		level++;
		damage *= UPGRADE_RATE;
		speed *= UPGRADE_RATE;		
		range++;
	}
}

void Tower::downgradeTw()
{
	if (level > 0)
	{
		level--;
		damage /= UPGRADE_RATE;
		speed /= UPGRADE_RATE;
		range--;
	}
	if (level == 0)
		this->~Tower();//Delete this tower
}



void Tower::showRangeCircle()
{
	
}
