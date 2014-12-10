#include "SlowAttack.h"
#include "LevelManager.h"


SlowAttack::SlowAttack()
{
}

void SlowAttack::attackAnimation(sf::RenderWindow& w)
{
	attackRay.setSize(sf::Vector2f(2, targetDistance));
	attackRay.setPosition(sf::Vector2f(center));
	attackRay.setFillColor(sf::Color(255, 0, 0, 100));
	setAttackRayAngle();

	w.draw(attackRay);
}

/*
Resolve slow effect of the enemy who is closest to the final target in the range.
The slow effect will occure in a frequency defined by timer.
*/

void SlowAttack::resolve(sf::RenderWindow& w)
{
	//TODO:Animation
	if (timer == 0)
	{
		shared_ptr<Enemy> enemy = getTarget();
		if (enemy != NULL){
			enemy->slow(slowAmount);
			timer = speed;
			attackAnimation(w);
		}
	}
	else
		timer--;
}