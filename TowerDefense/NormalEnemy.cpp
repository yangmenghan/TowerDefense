#include "NormalEnemy.h"
#include "Config.h"

NormalEnemy::NormalEnemy(){
	hp = NORMAL_ENEMY_HP;
	defence = NORMAL_ENEMY_DEFENCE;
	bounty = NORMAL_ENEMY_BOUNTY;
	scoreValue = NORMAL_ENEMY_SCOREVALUE;
	speed = NORMAL_ENEMY_SPEED;

	sf::Texture texture;
	if (!texture.loadFromFile(NORMAL_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
};

NormalEnemy::NormalEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed){
	Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed);
};

NormalEnemy::~NormalEnemy(){
};