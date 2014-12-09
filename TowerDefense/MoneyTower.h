#pragma once
#include "Tower.h"
#include "NormalAttack.h"

class MoneyTower :
	public Tower
{
public:
	MoneyTower(shared_ptr<Tile> mTile);
	MoneyTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	virtual ~MoneyTower(){};

	void upgradeTw();
	void downgradeTw();
	void generateMoney();
	void doAttack() override;
	void showRangeCircle(sf::RenderWindow& w)override;
};

