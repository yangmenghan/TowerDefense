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

	Enemy getTarget();
	void virtual resolve();

protected:
	float slowAmount;
	float damage;
	float range;
	sf::Vector2i center;
	int timer;
	int speed;
};

