#include "NormalAttack.h"



NormalAttack::NormalAttack()
{
}


NormalAttack::~NormalAttack()
{
}

void NormalAttack::resolve()
{
	//TODO:Animation
	if (timer == 0)
	{
		Enemy enemy = getTarget();
		enemy.takeDamage(damage);
		timer = speed;
	}

	else
		timer--;
}