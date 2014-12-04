#include "ToughEnemy.h"
#include "Config.h"

ToughEnemy::ToughEnemy() :Enemy(TOUGH_ENEMY_HP, TOUGH_ENEMY_DEFENCE, TOUGH_ENEMY_BOUNTY, TOUGH_ENEMY_SCOREVALUE, sf::Sprite(), TOUGH_ENEMY_SPEED){

	if (!texture.loadFromFile(TOUGH_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
};

ToughEnemy::ToughEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed)
	:Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed){};
