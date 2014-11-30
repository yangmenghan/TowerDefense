#include "Attack.h"
#include "LevelManager.h"

Attack::Attack()
{
	timer = speed;
}

Attack::~Attack()
{
}

/*
Setters and Getters.
*/
float Attack::getDamage()
{
	return damage;
}

float Attack::getSlowAmount()
{
	return slowAmount;
}

void Attack::setDamage(float mDamage)
{
	damage = mDamage;
}

void Attack::setSlowAmount(float mFloatAmount)
{
	slowAmount = mFloatAmount;
}

void Attack::setCenter(sf::Vector2i mCenter)
{
	center = mCenter;
}

void Attack::setRange(float mRange)
{
	range = mRange;
}

void Attack::setSpeed(int mSpeed)
{
	speed = mSpeed;
}

/*
Return the pointer to the enenmy (in the range of tower) who is the closest to the final target. 
*/
Enemy* Attack::getTarget()
{
	std::vector<Enemy*> enemiesField = LevelManager::getLevelManager()->getEnemies();
	Enemy e;
	Enemy* enemyMinDistanceToTarget = &e;
	float minDistance = 0;
	for (Enemy* e : enemiesField)
	{
		if (sqrt((e->getPosition().x - center.x) ^ 2 + (e->getPosition().y - center.y) ^ 2) < range)
		{
			if (minDistance == 0)
			{
				minDistance = e->getDistanceToTarget();
				enemyMinDistanceToTarget = e;
			}
			else if (e->getDistanceToTarget() < minDistance)
			{
				minDistance = e->getDistanceToTarget();
				enemyMinDistanceToTarget = e;
			}
		}
	}
	return enemyMinDistanceToTarget;
}
