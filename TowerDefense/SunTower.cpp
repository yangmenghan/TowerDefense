#include "SunTower.h"


SunTower::SunTower(shared_ptr<Tile> mTile)
	:Tower(mTile)
{
	for (int i = 0; i < 3; i++)
	{
		damage[i] = SUN_TOWER_DAMAGE[i];
		income[i] = SUN_TOWER_INCOME[i];
		range[i] = SUN_TOWER_RANGE[i];
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

void SunTower::doAttack(sf::RenderWindow& w)
{
	attack->resolve(w);
}

