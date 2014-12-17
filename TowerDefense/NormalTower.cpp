#include "NormalTower.h"


NormalTower::NormalTower(shared_ptr<Tile> mTile)
	:Tower(mTile)
{
	for (int i = 0; i < 3; i++)
	{
		damage[i] = NORMAL_TOWER_DAMAGE[i];
		income[i] = NORMAL_TOWER_INCOME[i];
		range[i] = NORMAL_TOWER_RANGE[i];
		speed[i] = NORMAL_TOWER_SPEED[i] * LevelManager::getLevelManager()->getSpeed();

	}
	timer = speed[level - 1];
	price = NORMAL_TOWER_PRICE;

	attack = make_shared<NormalAttack>();
	setAttack();
	
	if (!texture.loadFromFile(NORMAL_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	setTowerTexture();
	setRangeCircle();
}

/*
Activate attack
*/

void NormalTower::doAttack(sf::RenderWindow& w) 
{
	attack->resolve(w);
}

void NormalTower::draw(sf::RenderWindow& w){
	sprite.setRotation(attack->getAttackRay().getRotation()+90);
	w.draw(sprite);
}
