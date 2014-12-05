#include "ToughEnemy.h"
#include "Config.h"

ToughEnemy::ToughEnemy() :Enemy(TOUGH_ENEMY_HP, TOUGH_ENEMY_DEFENCE, TOUGH_ENEMY_BOUNTY, TOUGH_ENEMY_SCOREVALUE, sf::Sprite(), TOUGH_ENEMY_SPEED){

	if (!texture.loadFromFile(TOUGH_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(TILE_WIDTH, TILE_HEIGHT)));
	sprite.setPosition(sf::Vector2f(float(position.x + TILE_WIDTH), float(position.y + TILE_HEIGHT)));
};

ToughEnemy::ToughEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed)
	:Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed)
{
	if (!texture.loadFromFile(TOUGH_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(TILE_WIDTH, TILE_HEIGHT)));
	sprite.setPosition(sf::Vector2f(float(position.x + TILE_WIDTH), float(position.y + TILE_HEIGHT)));
};
