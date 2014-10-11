#pragma once
#include "Entity.h"
#include <SFML\Graphics.hpp>
 
class Enemy : public Entity{
public :
	Enemy();
	Enemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed);

	bool move();
	void succed();
	void die();
	void slow(int);

	int getHP();
	int getBounty();
	int getScoreValue();
	float getDefence();
	int getSlowTime();

	void takeDamage(int);

protected:
	int hp;
	float defence;
	int bounty;
	int scoreValue;
	int slowTime;
};

