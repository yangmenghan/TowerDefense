#pragma once
#include "Tower.h"
#include "AreaAttack.h"

class SunTower :
	public Tower
{
public:
	SunTower();
	SunTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	~SunTower();

	void doAttack();
private:
	AreaAttack attack;
};

