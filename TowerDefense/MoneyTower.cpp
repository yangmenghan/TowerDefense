#include "MoneyTower.h"


MoneyTower::MoneyTower(shared_ptr<Tile> mTile)
	:Tower(mTile)
{
	for (int i = 0; i < 3; i++)
	{
		income[level - 1] = MONEY_TOWER_INCOME[level - 1];
	}
	price = MONEY_TOWER_PRICE;
	timer = speed;

	if (!texture.loadFromFile(MONEY_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
	sf::Vector2i spriteInit(0, currentSprite * size.y);
	sprite.setTextureRect(sf::IntRect(spriteInit, size));
	sprite.setPosition(sf::Vector2f(tile->getPositionPixel().x, tile->getPositionPixel().y));
}

void MoneyTower::doAttack()
{
	generateMoney();
}

void MoneyTower::showRangeCircle(sf::RenderWindow& w)
{

}

/*
Generate money in a frequency defined by timer
*/

void MoneyTower::generateMoney()
{
	if (timer == 0)
	{
		LevelManager::getLevelManager()->getPlayer()->manageMoney(MONEY_TOWER_GENERATION_UNIT[level - 1]);
		int c = LevelManager::getLevelManager()->getPlayer()->getMoney();
		timer = speed;
	}
	else
		timer--;
}
