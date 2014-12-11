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
		float i = sqrt(pow(e->getPosition().x + 25 - center.x, 2)
			+ pow((e->getPosition().y + 25 - center.y), 2));
		if (i < (float)(speed - timer) / (float)speed * range)
			enemiesInRange.push_back(e);
	}

	return enemiesInRange;
}
void AreaAttack::attackAnimation(sf::RenderWindow& w)
{
	attackCircle.setPosition(sf::Vector2f(center));
	attackCircle.setFillColor(sf::Color(0, 255, 255, 100));
	attackCircle.setOutlineColor(sf::Color(0, 255, 255, 255));
	attackCircle.setRadius((float)(speed - timer)/(float)speed * range);
	attackCircle.setOrigin(attackCircle.getRadius(), attackCircle.getRadius());

	w.draw(attackCircle);
}

/*
Resolve damages of enemies who are in the range. 
The damage will occure in a frequency defined by timer.
*/
void AreaAttack::resolve(sf::RenderWindow& w)
{
	//TODO:Animation
	if (timer == 0)
	{
			timer = speed;
	}
	else
	{
		vector<shared_ptr<Enemy>> enemiesInRange = getTarget();
		if (!enemiesInRange.empty())
		{

			for (shared_ptr<Enemy> e : enemiesInRange)
			{
				e->takeDamage(damage);
			}
		}
		attackAnimation(w);
		timer--;
	}
}