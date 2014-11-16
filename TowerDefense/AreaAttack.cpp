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

void Attack::resolve()
{
	//TODO:¼õÑª£¬¶¯»­
	vector<Enemy*> enemiesInRange(getTarget());

}