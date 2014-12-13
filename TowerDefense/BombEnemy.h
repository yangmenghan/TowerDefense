#pragma once
#include "Enemy.h"
#include "Tile.h"
#include <SFML\Graphics.hpp>
#include <vector>

using namespace std;

class BombEnemy : public Enemy{
public:
	BombEnemy();
	BombEnemy(int hp, float defence, int bounty, int scoreValue, int trigger, sf::Sprite sprite, float speed);
	~BombEnemy(){};

	int getTrigger();
	int getTimer();

	void explode();
	void TriggerCountDown();
	void checkCountDown();
	bool move() override;

private:
	int trigger;		//(percentage) HP threshold which triggers explosion countdown 
	int timer;			//number of seconds before explosion
	vector<Tile> range;	//

};