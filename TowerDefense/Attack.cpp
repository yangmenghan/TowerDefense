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

void Attack::setAttackRayAngle(shared_ptr<Enemy> target)
{
	float angle;
	int targetX = target->getPosition().x + 25;
	int targetY = target->getPosition().y + 25;
	if (targetX > center.x && targetY == center.y)
	{
		angle = 0;
	}
	else if (targetX > center.x && targetY > center.y)
	{
		angle = 180 / 3.14 
			* acos((float)(targetX - center.x) / targetDistance);
	}
	else if (targetX == center.x && targetY > center.y)
	{
		angle = 90;
	}
	else if (targetX < center.x && targetY > center.y)
	{
		angle = 180 / 3.14
			* acos((float)(targetY - center.y) / targetDistance)
			+ 90;
	}
	else if (targetX < center.x && targetY == center.y)
	{
		angle = 180;
	}
	else if (targetX < center.x && targetY < center.y)
	{
		float a = acos((float)(center.x - targetX) / targetDistance);
		angle = 180 / 3.14
			* acos((float)(center.x - targetX) / targetDistance)
			+ 180;
		int i = 0;

	}
	else if (targetX == center.x && targetY < center.y)
	{
		angle = 270;
	}
	else
	{
		angle = 180 / 3.14
			* acos((float)(center.y - targetY) / targetDistance)
			+ 270;
	}
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
		float i = sqrt(pow(e->getPosition().x + 25 - center.x, 2) //position of enemy is left-top point, so add 25 (half of enemy size) to compute
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
	
	return enemyMinDistanceToTarget;
}

sf::RectangleShape Attack::getAttackRay()
{
	return attackRay;
}