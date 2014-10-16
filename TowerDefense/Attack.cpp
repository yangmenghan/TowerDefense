#include "Attack.h"

Attack::Attack()
{
}

Attack::~Attack()
{
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

void Attack::resolve(int type)
{
	//¼õÑª£¬¶¯»­
	switch (type)
	{
	case NORMAL:

		break;
	case SLOW:

		break;
	case SUN:

		break;
	case MONEY:

		break;
	}
}
