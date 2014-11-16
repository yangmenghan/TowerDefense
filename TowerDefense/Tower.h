#pragma once
#include "Entity.h"
#include "Config.h"
#include "LevelManager.h"
#include "Attack.h"

class Tower :
	public Entity
{
public:
	
	Tower(Tile &mTile);
	~Tower();

	float getDamage();
	int getPrice();
	int getLevel();
	float getRange();

	void setDamage(float mDamage);
	void setPrice(int mPrice);
	void setLevel(int mLevel);
	void setRange(float mRange);

	void virtual sellTw();
	void upgradeTw();
	void downgradeTw();
	void virtual doAttack();
	void showRangeCircle(); 

protected:
	Attack attack;
	float damage;
	int price;
	int income;
	int level;
	float range;
	sf::CircleShape rangeCircle;
};

