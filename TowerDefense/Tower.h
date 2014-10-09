#pragma once
#include "Entity.h"
class Tower :
	public Entity
{
protected:
	float damage;
	int price;
	int level;
	float range;
public:
	Tower();
	~Tower();

	float getDamage();
	int getPrice();
	int getLevel();
	float getRange();

	void setDamage(float _damage);
	void setPrice(int _price);
	void setLevel(int _level);
	void setRange(float _range);

	void sellTw();
	void upgradeTw();
	void downgradeTw();
	sf::Vector2f getTarget();

};

