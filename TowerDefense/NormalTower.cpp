#include "NormalTower.h"


NormalTower::NormalTower()
{
	damage = NORMAL_TOWER_DAMAGE;
	price = NORMAL_TOWER_PRICE;
	level = 1;
	range = NORMAL_TOWER_RANGE;
	speed = NORMAL_TOWER_SPEED;

	sf::Texture texture;
	if (!texture.loadFromFile(NORMAL_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
}

NormalTower::NormalTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite)
{
	Tower(mDamage, mPrice, mLevel, mRange, mSpeed, mSprite);
}

NormalTower::~NormalTower()
{
}

void NormalTower::attack()
{

}