#pragma once
#include "Tower.h"
#include "SingleAttack.h"

class NormalTower :
	public Tower
{
public:
	NormalTower();
	NormalTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	~NormalTower();

	void doAttack();
private:
	SingleAttack attack;
};

