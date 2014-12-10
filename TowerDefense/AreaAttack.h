#pragma once
#include "Attack.h"

class AreaAttack :
	public Attack
{
public:
	AreaAttack();
	virtual ~AreaAttack();

	vector<shared_ptr<Enemy>> getTarget();
	void attackAnimation(sf::RenderWindow& w) override;
	void resolve(sf::RenderWindow& w) override;
private:
	sf::CircleShape attackCircle;
};

