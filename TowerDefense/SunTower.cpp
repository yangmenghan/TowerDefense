#include "SunTower.h"


SunTower::SunTower(Tile mTile)
	:Tower(mTile)
{
	towerType = SUN;
	damage = SUN_TOWER_DAMAGE;
	price = SUN_TOWER_PRICE;
	income = int(price * INCOME_RATE);
	level = 1;
	range = SUN_TOWER_RANGE;
	speed = SUN_TOWER_SPEED;

	sf::Texture texture;
	if (!texture.loadFromFile(SUN_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);

	rangeCircle.setPosition(sf::Vector2f(this->getPosition()));
	rangeCircle.setRadius(range);
	rangeCircle.setOutlineThickness(2);
	rangeCircle.setFillColor(sf::Color(0, 0, 255, 100));
}

SunTower::~SunTower()
{
}

void Tower::sellTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(income);
}

void SunTower::doAttack()
{
	attack.resolve();
}
