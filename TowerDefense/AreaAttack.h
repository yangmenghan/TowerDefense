#pragma once
#include "Attack.h"

class AreaAttack :
	public Attack
{
public:
	AreaAttack();
	~AreaAttack();

	float getRange();

	void setRange();

	sf::Vector2f getTarget();

private:
	float range;
};

