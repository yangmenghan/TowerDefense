#pragma once
#include "Entity.h"
#include <SFML\Graphics.hpp>
 
class Enemy : public Entity{
public :
	Enemy();
	Enemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed);

	virtual bool move();
	void succed();
	void die();
	void dieWithoutBonus();
	void slow(int);
	void unSlow();

	int getHP();
	int getBounty();
	int getScoreValue();
	float getDefence();
	int getSlowTime();
	float getDistanceToTarget();

	virtual string test() = 0;

	void setTile(shared_ptr<Tile>);

	void takeDamage(int);

protected:
	int hp;
	float defence;
	int bounty;
	int scoreValue;
	int slowTime;
};

