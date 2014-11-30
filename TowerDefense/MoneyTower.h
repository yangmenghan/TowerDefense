#pragma once
#include "Tower.h"

class MoneyTower :
	public Tower
{
public:
	MoneyTower(Tile mTile);
	MoneyTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	virtual ~MoneyTower(){};

	void generateMoney();
	void doAttack() override;
};

