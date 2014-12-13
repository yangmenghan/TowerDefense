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
	virtual ~Tower();

	float getDamage();
	int getPrice();
	int getLevel();
	float getRange();
	int getIncome();

	void setDamage(float mDamage);
	void setPrice(int mPrice);
	void setLevel(int mLevel);
	void setRange(float mRange);
	void setAttack();
	void setTowerTexture();
	void setRangeCircle();

	void sellTw();
	void upgradeTw();
	void downgradeTw();
	virtual void doAttack(sf::RenderWindow& w) = 0;

	void spriteUpdate(int i);
	void showRangeCircle(sf::RenderWindow& w); 

protected:
	shared_ptr<Attack> attack;
	float damage[3];
	int slowAmount[3];
	float range[3];
	int speed[3];
	int income[3];
	int price;
	int level;
	int currentSprite;

	sf::CircleShape rangeCircle;
	
};

