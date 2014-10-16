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

	void resolve(int type);
protected:
	float slowAmount;
	float damage;
	typedef enum TowerType{NORMAL, SLOW, SUN, MONEY};
};

