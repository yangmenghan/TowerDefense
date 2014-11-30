#pragma once
#include "Entity.h"
#include "Config.h"
#include "LevelManager.h"
#include "Attack.h"
#include <memory>

class Tower :
	public Entity
{
public:
	Tower(Tile &mTile);
	Tower();
	~Tower();

	float getDamage();
	int getPrice();
	int getLevel();
	float getRange();

	void setDamage(float mDamage);
	void setPrice(int mPrice);
	void setLevel(int mLevel);
	void setRange(float mRange);

	void sellTw();
	void upgradeTw();
	void downgradeTw();
	void virtual doAttack() = 0;
	void showRangeCircle(); 

protected:
	shared_ptr<Attack> attack;
	float damage[3];
	int price;
	int income[3];
	int level;
	float range[3];


	sf::CircleShape rangeCircle;
};

