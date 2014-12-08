#include "NormalAttack.h"



NormalAttack::NormalAttack()
{
}

/*
Resolve damages of the enemy who is closest to the final target in the range.
The damage will occure in a frequency defined by timer.
*/

bool NormalAttack::hasTarget()
{
	if (target != NULL)
		return true;
	else
		return false;
}

void NormalAttack::setTarget(shared_ptr<Enemy> mTarget)
{
	target = mTarget;
}

void NormalAttack::resolve()
{
	//TODO:Animation
	if (timer == 0)
	{
		target = getTarget();
		int distance = sqrt((target->getPosition().x - center.x) ^ 2 + (target->getPosition().y - center.y) ^ 2);
		if (hasTarget() &&  distance > range)
			setTarget(NULL);
		else if (hasTarget() && distance < range)
		{
			target->takeDamage(damage);
			timer = speed;
		}

	}

	else
		timer--;
}