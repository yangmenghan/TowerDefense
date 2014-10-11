#pragma once
#include "Tower.h"
class SlowTower :
	public Tower
{
public:
	SlowTower();
	SlowTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	~SlowTower();

	void attack();
};

