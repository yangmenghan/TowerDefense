#include "AreaAttack.h"
#include "LevelManager.h"


AreaAttack::AreaAttack()
{
}


AreaAttack::~AreaAttack()
{
}

vector<shared_ptr<Enemy>> AreaAttack::getTarget()
{
	vector<shared_ptr<Enemy>> enemiesField = LevelManager::getLevelManager()->getEnemies();
	vector<shared_ptr<Enemy>> enemiesInRange;
	for (shared_ptr<Enemy> e : enemiesField)
	{
		if (sqrt((e->getPosition().x - center.x) ^ 2 + (e->getPosition().y - center.y) ^ 2) < range)
			enemiesInRange.push_back(e);
	}

	return enemiesInRange;
}

void AreaAttack::resolve()
{
	//TODO:Animation
	if (timer == 0)
	{
		vector<shared_ptr<Enemy>> enemiesInRange = getTarget();
		for (shared_ptr<Enemy> e : enemiesInRange)
		{
			e->takeDamage(damage);
		}
		timer = speed;
	}
	else
		timer--;
}