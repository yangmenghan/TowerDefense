#include "NormalEnemy.h"
#include "Config.h"
#include <SFML/Graphics.hpp>

NormalEnemy::NormalEnemy() :Enemy(NORMAL_ENEMY_HP, NORMAL_ENEMY_DEFENCE, NORMAL_ENEMY_BOUNTY, NORMAL_ENEMY_SCOREVALUE, sf::Sprite(), NORMAL_ENEMY_SPEED){

	if (!texture.loadFromFile(NORMAL_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(TILE_WIDTH, TILE_HEIGHT)));
	sprite.setPosition(sf::Vector2f(float(position.x + TILE_WIDTH), float(position.y + TILE_HEIGHT)));
};

NormalEnemy::NormalEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed):Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed)
{
	if (!texture.loadFromFile(NORMAL_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(TILE_WIDTH, TILE_HEIGHT)));
	sprite.setPosition(sf::Vector2f(float(position.x + TILE_WIDTH), float(position.y + TILE_HEIGHT)));
};
