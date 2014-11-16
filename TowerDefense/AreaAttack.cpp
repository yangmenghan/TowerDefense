#include "AreaAttack.h"


AreaAttack::AreaAttack()
{
}


AreaAttack::~AreaAttack()
{
}

vector<Enemy*> AreaAttack::getTarget()
{
	vector<Enemy*> enemiesField = LevelManager::getLevelManager().getEnemies();
	vector<Enemy*> enemiesInRange;
	for (Enemy* e : enemiesField)
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