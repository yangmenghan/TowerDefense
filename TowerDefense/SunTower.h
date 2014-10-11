#pragma once
#include "Tower.h"
class SunTower :
	public Tower
{
public:
	SunTower();
	SunTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	~SunTower();

	void attack();
};

