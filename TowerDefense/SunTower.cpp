#include "SunTower.h"


SunTower::SunTower(shared_ptr<Tile> mTile)
	:Tower(mTile)
{
	for (int i = 0; i < 3; i++)
	{
		damage[level - 1] = SUN_TOWER_DAMAGE[level - 1];
		income[level - 1] = SUN_TOWER_INCOME[level - 1];
		range[level - 1] = SUN_TOWER_RANGE[level - 1];
	}
	price = SUN_TOWER_PRICE;
	timer = speed;
	position = sf::Vector2i(tile->getPositionPixel().x + 25, tile->getPositionPixel().y + 25);

	attack = make_shared<AreaAttack>();
	attack->setCenter(position);
	attack->setDamage(damage[level - 1]);
	attack->setRange(range[level - 1]);
	attack->setSpeed(speed);
	attack->setTimer(timer);

	if (!texture.loadFromFile(SUN_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
	sf::Vector2i spriteInit(0, currentSprite * size.y);
	sprite.setTextureRect(sf::IntRect(spriteInit, size));
	sprite.setPosition(sf::Vector2f(tile->getPositionPixel().x, tile->getPositionPixel().y));

	rangeCircle.setOrigin(sf::Vector2f(range[level - 1], range[level - 1]));
	rangeCircle.setPosition(sf::Vector2f(position.x, position.y));
	rangeCircle.setRadius(range[level - 1]);
	rangeCircle.setFillColor(sf::Color(0, 0, 255, 100));
}

/*
Activate attck
*/

void SunTower::doAttack()
{
	attack->resolve();
}
void SunTower::showRangeCircle(sf::RenderWindow& w)
{
	w.draw(rangeCircle);
}
