#include "NormalAttack.h"



NormalAttack::NormalAttack()
{
}

void NormalAttack::attackAnimation(sf::RenderWindow& w)
{
	attackRay.setSize(sf::Vector2f(targetDistance, 2));
	attackRay.setPosition(sf::Vector2f(center));
	attackRay.setFillColor(sf::Color(255, 0, 0, 255));

	w.draw(attackRay);
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
			targetDistance = sqrt(pow(enemy->getPosition().x + 25 - center.x, 2)
				+ pow((enemy->getPosition().y + 25 - center.y), 2));
			setAttackRayAngle(enemy);
			attackAnimation(w);
			enemy->takeDamage(damage);
			timer = speed;
		}
	}
	else{
		timer--;
	}		
}