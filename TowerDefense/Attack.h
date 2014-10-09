#pragma once
#include <SFML/Graphics.hpp>

class Attack
{
private:
	float slowAmount;

protected:
	float damage;

public:
	Attack();
	~Attack();

	float getDamage();
	float getSlowAmount();

	void setDamage(float _damage);
	void setSlowAmount();

	void resolve();
};

