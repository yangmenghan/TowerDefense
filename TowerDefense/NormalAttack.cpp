#include "NormalAttack.h"



NormalAttack::NormalAttack()
{
}


void NormalAttack::resolve()
{
	//TODO:Animation
	if (timer == 0)
	{
		getTarget()->takeDamage(damage);
		timer = speed;
	}

	else
		timer--;
}