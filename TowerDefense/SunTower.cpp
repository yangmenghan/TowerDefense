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

	attack = make_shared<AreaAttack>();
	setAttack();

	if (!texture.loadFromFile(SUN_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}
	setTowerTexture();

	setRangeCircle();
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
