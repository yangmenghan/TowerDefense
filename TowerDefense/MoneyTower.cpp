#include "MoneyTower.h"


MoneyTower::MoneyTower(shared_ptr<Tile> mTile)
	:Tower(mTile)
{
	for (int i = 0; i < 3; i++)
	{
		damage[i] = SUN_TOWER_DAMAGE[i];
		income[i] = SUN_TOWER_INCOME[i];
		range[i] = SUN_TOWER_RANGE[i];
	}
	price = MONEY_TOWER_PRICE;

	if (!texture.loadFromFile(MONEY_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}
	setTowerTexture();
	
	attack = make_shared<NormalAttack>();
	setAttack();
	setRangeCircle();
}

void MoneyTower::doAttack(sf::RenderWindow& w)
{
	generateMoney();
}

/*
Generate money in a frequency defined by timer
*/

void MoneyTower::generateMoney()
{
	if (timer == 0)
	{
		LevelManager::getLevelManager()->getPlayer()->manageMoney(MONEY_TOWER_GENERATION_UNIT[level - 1]);
		sprite.setColor(sf::Color(255, 255, 0, 100));
		timer = speed;
	}
	else
	{
		sprite.setColor(sf::Color(255, 255, 255, 255));
		timer--;
	}
}
