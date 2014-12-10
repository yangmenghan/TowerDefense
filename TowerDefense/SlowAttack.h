#pragma once
#include "Attack.h"

class SlowAttack :
	public Attack
{
public:
	SlowAttack();
	virtual ~SlowAttack(){};

	void attackAnimation(sf::RenderWindow& w) override;
	void resolve(sf::RenderWindow& w) override;
};

