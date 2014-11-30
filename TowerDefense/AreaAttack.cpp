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
vector<Enemy*> AreaAttack::getTarget()
{
	vector<Enemy*> enemiesField = LevelManager::getLevelManager()->getEnemies();
	vector<Enemy*> enemiesInRange;
	for (Enemy* e : enemiesField)
	{
		if (sqrt((e->getPosition().x - center.x) ^ 2 + (e->getPosition().y - center.y) ^ 2) < range)
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
		vector<Enemy*> enemiesInRange = getTarget();
		for (Enemy* e : enemiesInRange)
		{
			e->takeDamage(damage);
		}
		timer = speed;
	}
	else
		timer--;
}