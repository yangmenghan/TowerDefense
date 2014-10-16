#pragma once
#include "Tower.h"
#include "SingleAttack.h"

class SlowTower :
	public Tower
{
public:
	SlowTower();
	SlowTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	~SlowTower();

	void doAttack();
private:
	SingleAttack attack;
};

