#include "SlowTower.h"


SlowTower::SlowTower(shared_ptr<Tile> mTile)
	:Tower(mTile)
{
	for (int i = 0; i < 3; i++)
	{
		slowAmount[i] = SLOW_TOWER_SLOW_AMOUNT[i];
		income[i] = SLOW_TOWER_INCOME[i];
		range[i] = SLOW_TOWER_RANGE[i];
	}
	price = SLOW_TOWER_PRICE;

	attack = make_shared<SlowAttack>();
	setAttack();

	if (!texture.loadFromFile(SLOW_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}
	setTowerTexture();
	setRangeCircle();
}


void SlowTower::doAttack(sf::RenderWindow& w)
{

	attack->resolve(w);
}

