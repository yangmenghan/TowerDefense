#include "Attack.h"
#include "LevelManager.h"
#include "NormalEnemy.h"
#include <memory>

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
sf::Vector2i Attack::getCenter()
{
	return center;
}

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

void Attack::setTimer(int mTimer)
{
	timer = mTimer;
}

/*
Return the pointer to the enenmy (in the range of tower) who is the closest to the final target. 
*/

shared_ptr<Enemy> Attack::getTarget()
{
	//std::vector<shared_ptr<Enemy>> enemiesField = LevelManager::getLevelManager()->getEnemies();
	shared_ptr<Enemy> enemyMinDistanceToTarget = NULL;
	float minDistance = 0;
	for (shared_ptr<Enemy> e : LevelManager::getLevelManager()->getEnemies())
	{
		float i = sqrt(pow(e->getPosition().x - center.x, 2) + pow((e->getPosition().y - center.y),2));
		if ( i < range)
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
