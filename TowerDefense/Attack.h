#pragma once
#include <SFML/Graphics.hpp>

class Attack
{

public:
	Attack();
	~Attack();

	float getDamage();
	float getSlowAmount();

	void setDamage(float mDamage);
	void setSlowAmount(float mSlowAmount);

	void virtual resolve();

protected:
	float slowAmount;
	float damage;
	enum TowerType{NORMAL, SLOW, SUN, MONEY};
};

