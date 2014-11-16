#include "Tower.h"
#include "Player.h"
#include "LevelManager.h"

Tower::Tower(Tile mTile)
{
	this->tile = mTile;

	this->attack.setDamage(damage);
	this->attack.setSlowAmount(damage);
	this->attack.setRange(range);
	this->attack.setSpeed(speed);
	this->timer = speed;
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
		damage += UPGRADE_INCREMENT;
		speed -= UPGRADE_INCREMENT;		
		range++;

		attack.setDamage(damage);
		attack.setSlowAmount(damage);
		attack.setSpeed(speed);
		attack.setRange(range);
	}
}

void Tower::downgradeTw()
{
	if (level > 0)
	{
		level--;
		damage -= UPGRADE_INCREMENT;
		speed += UPGRADE_INCREMENT;
		range--;
		
		attack.setDamage(damage);
		attack.setSlowAmount(damage);
		attack.setSpeed(speed);
		attack.setRange(range);
	}
	if (level == 0)
		this->~Tower();//Delete this tower
}




