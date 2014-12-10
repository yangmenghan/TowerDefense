#pragma once
#include "Attack.h"

class NormalAttack :
	public Attack
{
public:
	NormalAttack();
	virtual ~NormalAttack(){};

	void attackAnimation(sf::RenderWindow& w) override;
	void resolve(sf::RenderWindow& w) override;

};

