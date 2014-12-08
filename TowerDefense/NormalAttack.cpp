#include "NormalAttack.h"



NormalAttack::NormalAttack()
{
}

/*
Resolve damages of the enemy who is closest to the final target in the range.
The damage will occure in a frequency defined by timer.
*/

void NormalAttack::resolve()
{
	//TODO:Animation
	if (timer == 0)
	{
		shared_ptr<Enemy> enemy = getTarget();
		if (enemy !=NULL){
			getTarget()->takeDamage(damage);
			timer = speed;
		}
		
	}
	else{
		timer--;
	}
		
}