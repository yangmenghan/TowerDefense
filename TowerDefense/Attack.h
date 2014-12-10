#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Attack
{

public:
	Attack();
	~Attack();

	float getDamage();
	float getSlowAmount();

	void setDamage(float mDamage);
	void setSlowAmount(float mSlowAmount);
	void setCenter(sf::Vector2i mCenter);
	void setRange(float mRange);
	void setSpeed(int mSpeed);
	void setTimer(int mTimer);


	shared_ptr<Enemy> getTarget();
	sf::Vector2i getCenter();
	void setAttackRayAngle(shared_ptr<Enemy> target);
	void virtual attackAnimation(sf::RenderWindow& w) = 0;
	void virtual resolve(sf::RenderWindow& w) = 0;

protected:
	float slowAmount;
	float damage;
	float range;
	sf::Vector2i center;
	int timer;
	int speed;
	float targetDistance;

	sf::RectangleShape attackRay;
};

