#include "MoneyTower.h"


MoneyTower::MoneyTower()
{
	damage = MONEY_TOWER_DAMAGE;
	price = MONEY_TOWER_PRICE;
	level = 1;
	range = MONEY_TOWER_RANGE;
	speed = MONEY_TOWER_SPEED;

	sf::Texture texture;
	if (!texture.loadFromFile(MONEY_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
}

MoneyTower::MoneyTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite)
{
	Tower(mDamage, mPrice, mLevel, mRange, mSpeed, mSprite);
}

MoneyTower::~MoneyTower()
{
}

void MoneyTower::generateMoney()
{

}