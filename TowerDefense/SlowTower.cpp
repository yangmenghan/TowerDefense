#include "SlowTower.h"


SlowTower::SlowTower()
{
	damage = SLOW_TOWER_DAMAGE;
	price = SLOW_TOWER_PRICE;
	level = 1;
	range = SLOW_TOWER_RANGE;
	speed = SLOW_TOWER_SPEED;

	sf::Texture texture;
	if (!texture.loadFromFile(SLOW_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
}

SlowTower::SlowTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite)
{
	Tower(mDamage, mPrice, mLevel, mRange, mSpeed, mSprite);
}

SlowTower::~SlowTower()
{
}

void SlowTower::attack()
{

}
