#include "ToughEnemy.h"
#include "Config.h"

ToughEnemy::ToughEnemy(){
	hp = TOUGH_ENEMY_HP;
	defence = TOUGH_ENEMY_DEFENCE;
	bounty = TOUGH_ENEMY_BOUNTY;
	scoreValue = TOUGH_ENEMY_SCOREVALUE;
	speed = TOUGH_ENEMY_SPEED;

	sf::Texture texture;
	if (!texture.loadFromFile(TOUGH_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
};

ToughEnemy::ToughEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed){
	Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed);
};

ToughEnemy::~ToughEnemy(){
};