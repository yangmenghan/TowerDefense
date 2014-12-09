#include "AreaAttack.h"
#include "LevelManager.h"


AreaAttack::AreaAttack()
{
}


AreaAttack::~AreaAttack()
{
}

/*
Return a list of pointers to enemies, who are in the range of tower. 
*/

vector<shared_ptr<Enemy>> AreaAttack::getTarget()
{
	vector<shared_ptr<Enemy>> enemiesField = LevelManager::getLevelManager()->getEnemies();
	vector<shared_ptr<Enemy>> enemiesInRange;
	for (shared_ptr<Enemy> e : enemiesField)
	{
		float i = sqrt(pow(e->getPosition().x - center.x, 2)
			+ pow((e->getPosition().y - center.y), 2));
		if (i < range)
			enemiesInRange.push_back(e);
	}

	return enemiesInRange;
}
/*
Resolve damages of enemies who are in the range. 
The damage will occure in a frequency defined by timer.
*/
void AreaAttack::resolve()
{
	//TODO:Animation
	if (timer == 0)
	{
		vector<shared_ptr<Enemy>> enemiesInRange = getTarget();
		if (!enemiesInRange.empty())
		{
			for (shared_ptr<Enemy> e : enemiesInRange)
			{
				e->takeDamage(damage);
			}
			timer = speed;
		}
	}
	else
		timer--;
}