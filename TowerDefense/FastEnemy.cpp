#include "FastEnemy.h"
#include "Config.h"

FastEnemy::FastEnemy(){
	hp = FAST_ENEMY_HP;
	defence = FAST_ENEMY_DEFENCE;
	bounty = FAST_ENEMY_BOUNTY;
	scoreValue = FAST_ENEMY_SCOREVALUE;
	speed = FAST_ENEMY_SPEED;

	sf::Texture texture;
	if (!texture.loadFromFile(FAST_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
};

FastEnemy::FastEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed){
	Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed);
};

FastEnemy::~FastEnemy(){
};