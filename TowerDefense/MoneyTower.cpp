#include "MoneyTower.h"


MoneyTower::MoneyTower(Tile mTile)
	:Tower(mTile)
{
	damage[level - 1] = MONEY_TOWER_DAMAGE[level - 1];
	price = MONEY_TOWER_PRICE;
	income[level - 1] = MONEY_TOWER_INCOME[level - 1];
	range[level - 1] = MONEY_TOWER_RANGE[level - 1];

	attack.setDamage(damage[level - 1]);
	attack.setRange(range[level - 1]);
	attack.setSpeed(speed);

	timer = speed;

	sf::Texture texture;
	if (!texture.loadFromFile(MONEY_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);

	rangeCircle.setPosition(sf::Vector2f(this->getPosition()));
	rangeCircle.setRadius(range[level - 1]);
	rangeCircle.setOutlineThickness(2);
	rangeCircle.setFillColor(sf::Color(0, 0, 255, 100));
}

MoneyTower::~MoneyTower()
{
}

void MoneyTower::generateMoney()
{
	while (this)
	{
		if (timer == 0)
		{
			LevelManager::getLevelManager()->getPlayer().manageMoney(MONEY_TOWER_GENERATION_UNIT[level - 1]);
			timer = speed;
		}
		else
			timer--;
	}
}