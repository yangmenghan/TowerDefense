#include "FastEnemy.h"
#include "Config.h"

FastEnemy::FastEnemy() :Enemy(FAST_ENEMY_HP, FAST_ENEMY_DEFENCE, FAST_ENEMY_BOUNTY, FAST_ENEMY_SCOREVALUE, sf::Sprite(), FAST_ENEMY_SPEED){

	sf::Texture texture;
	if (!texture.loadFromFile(FAST_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
};

FastEnemy::FastEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed) :Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed){};
