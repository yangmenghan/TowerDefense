#include "Tower.h"
#include "Player.h"
#include "LevelManager.h"

Tower::Tower()
{
}

Tower::Tower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite)
{
	damage = mDamage;
	price = mPrice;
	income = int(price * INCOME_RATE);
	level = mLevel;
	range = mRange;
	speed = mSpeed;
	sprite = mSprite;

	rangeCircle.setPosition(this->getPosition());
	rangeCircle.setRadius(range);
	rangeCircle.setOutlineThickness(2);
	rangeCircle.setFillColor(RANGE_CIRCLE_FILL_COLOR);
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

int Tower::getTowerType()
{
	return towerType;
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
	if (level < 3)
		level++;
}

void Tower::downgradeTw()
{
	if (level > 0)
		level--;
}

Enemy Tower::getTarget()
{
	std::vector<Enemy>* enemiesField = LevelManager::getLevelManager().ge;
	Enemy enemyMinDistanceToTarget;
	float minDistance = 0;
	for (Enemy e : *enemiesField)
	{
		if (minDistance == 0)
		{
			minDistance = e.getDistanceToTarget;
			enemyMinDistanceToTarget = e;
		}
		else if (e.getDistanceToTarget() < minDistance)
		{
			minDistance = e.getDistanceToTarget;
			enemyMinDistanceToTarget = e;
		}
	}

	return enemyMinDistanceToTarget;
}

void Tower::showRangeCircle()
{
	
}
