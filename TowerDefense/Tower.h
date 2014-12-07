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
	Tower(shared_ptr<Tile>);
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
	virtual void doAttack() = 0;

	void spriteUpdate(int i);
	void showRangeCircle(); 

protected:
	shared_ptr<Attack> attack;
	float damage[3];
	int price;
	int income[3];
	int level;
	float range[3];

	int currentSprite;

	sf::CircleShape rangeCircle;
	
};

