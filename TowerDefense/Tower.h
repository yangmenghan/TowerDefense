#pragma once
#include "Entity.h"
#include "Config.h"
#include "LevelManager.h"

class Tower :
	public Entity
{
public:
	
	Tower();
	Tower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	~Tower();

	float getDamage();
	int getPrice();
	int getLevel();
	float getRange();
	int getTowerType();

	void setDamage(float mDamage);
	void setPrice(int mPrice);
	void setLevel(int mLevel);
	void setRange(float mRange);

	void sellTw();
	void upgradeTw();
	void downgradeTw();
	Enemy getTarget();
	void showRangeCircle(); 

protected:
	float damage;
	int price;
	int income;
	int level;
	float range;
	sf::CircleShape rangeCircle;
	enum TowerType {NORMAL, SLOW, SUN, MONEY} towerType;
};

