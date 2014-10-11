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
	void setSlowAmount();

	void resolve();

private:
	float slowAmount;

protected:
	float damage;
};

