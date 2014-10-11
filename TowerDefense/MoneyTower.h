#pragma once
#include "Tower.h"

class MoneyTower :
	public Tower
{
public:
	MoneyTower();
	MoneyTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	~MoneyTower();

	void generateMoney();
};

