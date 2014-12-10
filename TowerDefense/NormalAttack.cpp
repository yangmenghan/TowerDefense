#include "NormalAttack.h"



NormalAttack::NormalAttack()
{
}

void NormalAttack::attackAnimation(sf::RenderWindow& w)
{
	attackRay.setSize(sf::Vector2f(2, targetDistance));
	attackRay.setPosition(sf::Vector2f(center));
	attackRay.setFillColor(sf::Color(255, 0, 0, 255));
	//setAttackRayAngle();

	w.draw(attackRay);
	w.display();
}

/*
Resolve damages of the enemy who is closest to the final target in the range.
The damage will occure in a frequency defined by timer.
*/

void NormalAttack::resolve(sf::RenderWindow& w)
{
	//TODO:Animation
	if (timer == 0)
	{
		shared_ptr<Enemy> enemy = getTarget();
		if (enemy != NULL){
			enemy->takeDamage(damage);
			timer = speed;
			attackAnimation(w);
		}
	}
	else{
		timer--;
	}		
}