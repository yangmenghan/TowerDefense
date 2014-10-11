#include "SunTower.h"


SunTower::SunTower()
{
	damage = SUN_TOWER_DAMAGE;
	price = SUN_TOWER_PRICE;
	level = 1;
	range = SUN_TOWER_RANGE;
	speed = SUN_TOWER_SPEED;

	sf::Texture texture;
	if (!texture.loadFromFile(SUN_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
}

SunTower::SunTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite)
{
	Tower(mDamage, mPrice, mLevel, mRange, mSpeed, mSprite);
}

SunTower::~SunTower()
{
}

void SunTower::attack()
{

}
