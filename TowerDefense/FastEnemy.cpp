#include "FastEnemy.h"
#include "Config.h"

FastEnemy::FastEnemy() :Enemy(FAST_ENEMY_HP, FAST_ENEMY_DEFENCE, FAST_ENEMY_BOUNTY, FAST_ENEMY_SCOREVALUE, sf::Sprite(), FAST_ENEMY_SPEED){

	texture.loadFromFile(FAST_ENEMY_SPRITE_ADD);

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(TILE_WIDTH, TILE_HEIGHT)));
	sprite.setPosition(sf::Vector2f(float(position.x + TILE_WIDTH), float(position.y + TILE_HEIGHT)));
};

FastEnemy::FastEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed) :Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed)
{
	texture.loadFromFile(FAST_ENEMY_SPRITE_ADD);

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(TILE_WIDTH, TILE_HEIGHT)));
	sprite.setPosition(sf::Vector2f(float(position.x + TILE_WIDTH), float(position.y + TILE_HEIGHT)));
};
