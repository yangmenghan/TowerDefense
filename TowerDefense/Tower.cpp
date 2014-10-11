#include "Tower.h"

/*
protected:
float damage;
int price;
int level;
float range;
*/
Tower::Tower()
{
	damage = 0.0;
	price = 0;
	level = 0;
	range = 0.0;
	speed = 0.0;
}

Tower::Tower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite)
{
	damage = mDamage;
	price = mPrice;
	level = mLevel;
	range = mRange;
	speed = mSpeed;
	sprite = mSprite;
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


void Tower::sellTw()
{

}

void Tower::upgradeTw()
{

}

void Tower::downgradeTw()
{

}

sf::Vector2f Tower::getTarget()
{

}

