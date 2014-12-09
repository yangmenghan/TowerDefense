#include "SlowAttack.h"
#include "LevelManager.h"


SlowAttack::SlowAttack()
{
}

/*
Resolve slow effect of the enemy who is closest to the final target in the range.
The slow effect will occure in a frequency defined by timer.
*/

void SlowAttack::resolve()
{
	//TODO:Animation
	if (timer == 0)
	{
		shared_ptr<Enemy> enemy = getTarget();
		if (enemy != NULL){
			enemy->slow(slowAmount);
			timer = speed;
		}
	}
	else
		timer--;
}