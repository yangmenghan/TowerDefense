#pragma once
#include "Entity.h"
#include "Config.h"

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

	void setDamage(float mDamage);
	void setPrice(int mPrice);
	void setLevel(int mLevel);
	void setRange(float mRange);

	void sellTw();
	void upgradeTw();
	void downgradeTw();
	sf::Vector2f getTarget();

protected:
	float damage;
	int price;
	int level;
	float range;
};

