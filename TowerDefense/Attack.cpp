#include "Attack.h"
#include "LevelManager.h"
#include "NormalEnemy.h"
#include <memory>

Attack::Attack()
{
	timer = speed;
	targetDistance = 0;
	slowAmount = 0;
	damage = 0;
	range = 0;
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

void Attack::setAttackRayAngle()
{
	float angle;
	angle = acos(targetDistance/(float)(getTarget()->getPosition().x + 25));
	attackRay.setRotation(angle);
}

/*
Return the pointer to the enenmy (in the range of tower) who is the closest to the final target. 
*/

shared_ptr<Enemy> Attack::getTarget()
{
	shared_ptr<Enemy> enemyMinDistanceToTarget = NULL;
	float minDistance = 0;
	for (shared_ptr<Enemy> e : LevelManager::getLevelManager()->getEnemies())
	{
		float i = sqrt(pow(e->getPosition().x + 25 - center.x, 2) 
						+ pow((e->getPosition().y + 25 - center.y),2));
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
	targetDistance = minDistance;
	return enemyMinDistanceToTarget;
}
