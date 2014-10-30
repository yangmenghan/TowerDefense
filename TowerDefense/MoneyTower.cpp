#include "MoneyTower.h"


MoneyTower::MoneyTower()
{
	towerType = MONEY;
	damage = MONEY_TOWER_DAMAGE;
	price = MONEY_TOWER_PRICE;
	income = int(price * INCOME_RATE);
	level = 1;
	range = MONEY_TOWER_RANGE;
	speed = MONEY_TOWER_SPEED;

	sf::Texture texture;
	if (!texture.loadFromFile(MONEY_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);

	rangeCircle.setPosition(this->getPosition());
	rangeCircle.setRadius(range);
	rangeCircle.setOutlineThickness(2);
	rangeCircle.setFillColor(sf::Color(0, 0, 255, 100));
}

MoneyTower::MoneyTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite)
{
	Tower(mDamage, mPrice, mLevel, mRange, mSpeed, mSprite);
	towerType = MONEY;
}

MoneyTower::~MoneyTower()
{
}

void Tower::sellTw()
{
	LevelManager::getLevelManager().getPlayer().manageMoney(int(MONEY_TOWER_PRICE * INCOME_RATE));
}

void MoneyTower::generateMoney()
{
	while (this)
	{
		LevelManager::getLevelManager().getPlayer().manageMoney(MONEY_TOWER_GENERATION_UNIT);
		//How can it be hold on for seconds?
	}
}