#include "SlowTower.h"


SlowTower::SlowTower(Tile mTile)
	:Tower(mTile)
{
	level = 1;

	damage = SLOW_TOWER_DAMAGE[level-1];
	price = SLOW_TOWER_PRICE;
	income = SLOW_TOWER_INCOME[level-1];
	range = SLOW_TOWER_RANGE[level-1];
	speed = SLOW_TOWER_SPEED[level-1];

	sf::Texture texture;
	if (!texture.loadFromFile(SLOW_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);

	rangeCircle.setPosition(sf::Vector2f(this->getPosition()));
	rangeCircle.setRadius(range);
	rangeCircle.setOutlineThickness(2);
	rangeCircle.setFillColor(sf::Color(0, 0, 255, 100));
}

SlowTower::~SlowTower()
{
}

void Tower::sellTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(income);
}

void SlowTower::doAttack()
{
	attack.setSlowAmount(damage);
	attack.resolve();
}
