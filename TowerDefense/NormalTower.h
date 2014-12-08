#pragma once
#include "Tower.h"
#include "NormalAttack.h"

class NormalTower :
	public Tower
{
public:
	NormalTower(shared_ptr<Tile> mTile);
	NormalTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	virtual ~NormalTower(){};


	void doAttack()override;

private:
	NormalAttack attack;
	
};

