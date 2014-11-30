#include "NormalEnemy.h"
#include "Config.h"

NormalEnemy::NormalEnemy() :Enemy(NORMAL_ENEMY_HP, NORMAL_ENEMY_DEFENCE, NORMAL_ENEMY_BOUNTY, NORMAL_ENEMY_SCOREVALUE, sf::Sprite(), NORMAL_ENEMY_SPEED){

	sf::Texture texture;
	if (!texture.loadFromFile(NORMAL_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
};

NormalEnemy::NormalEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed):Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed){};
