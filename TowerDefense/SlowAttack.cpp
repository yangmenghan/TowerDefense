#include "SlowAttack.h"
#include "LevelManager.h"


SlowAttack::SlowAttack()
{
}


SlowAttack::~SlowAttack()
{
}

void SlowAttack::resolve()
{
	//TODO:Animation
	if (timer == 0)
	{
		Enemy enemy = getTarget();
		enemy.slow(slowAmount);
		timer = speed;
	}
	else
		timer--;
}