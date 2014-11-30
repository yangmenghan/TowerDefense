#pragma once
#include "Tower.h"
#include "SlowAttack.h"

class SlowTower :
	public Tower
{
public:
	SlowTower(Tile mTile);
	SlowTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	virtual ~SlowTower(){};

	void doAttack() override;
private:
	SlowAttack attack;
};

