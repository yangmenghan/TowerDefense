#include "SlowAttack.h"
#include "LevelManager.h"


SlowAttack::SlowAttack()
{
}


void SlowAttack::resolve()
{
	//TODO:Animation
	if (timer == 0)
	{
		getTarget()->slow(slowAmount);
		timer = speed;
	}
	else
		timer--;
}