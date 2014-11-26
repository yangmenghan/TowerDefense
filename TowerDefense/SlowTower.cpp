#include "SlowTower.h"


SlowTower::SlowTower(Tile mTile)
	:Tower(mTile)
{
	damage[level - 1] = SLOW_TOWER_DAMAGE[level - 1];
	price = SLOW_TOWER_PRICE;
	income[level - 1] = SLOW_TOWER_INCOME[level - 1];
	range[level - 1] = SLOW_TOWER_RANGE[level - 1];

	attack.setSlowAmount(damage[level - 1]);
	attack.setRange(range[level - 1]);
	attack.setSpeed(speed);

	timer = speed;

	sf::Texture texture;
	if (!texture.loadFromFile(SLOW_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);

	rangeCircle.setPosition(sf::Vector2f(this->getPosition()));
	rangeCircle.setRadius(range[level - 1]);
	rangeCircle.setOutlineThickness(2);
	rangeCircle.setFillColor(sf::Color(0, 0, 255, 100));
}

SlowTower::~SlowTower()
{
}



void SlowTower::doAttack()
{

	attack.resolve();
}
