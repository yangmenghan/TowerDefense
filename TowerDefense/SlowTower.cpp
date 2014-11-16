#include "SlowTower.h"


SlowTower::SlowTower(Tile mTile)
	:Tower(mTile)
{

	damage = SLOW_TOWER_DAMAGE;
	price = SLOW_TOWER_PRICE;
	income = int(price * INCOME_RATE);
	level = 1;
	range = SLOW_TOWER_RANGE;
	speed = SLOW_TOWER_SPEED;

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
	LevelManager::getLevelManager()->getPlayer().manageMoney(int(SLOW_TOWER_PRICE * INCOME_RATE));
}

void SlowTower::doAttack()
{
	attack.setSlowAmount(damage);
	attack.resolve();
}
