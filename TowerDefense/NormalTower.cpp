#include "NormalTower.h"


NormalTower::NormalTower(Tile mTile)
	:Tower(mTile)
{
	towerType = NORMAL;
	damage = NORMAL_TOWER_DAMAGE;
	price = NORMAL_TOWER_PRICE;
	income = int(price * INCOME_RATE);
	level = 1;
	range = NORMAL_TOWER_RANGE;
	speed = NORMAL_TOWER_SPEED;
	
	sf::Texture texture;
	if (!texture.loadFromFile(NORMAL_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);

	rangeCircle.setPosition(sf::Vector2f(this->getPosition()));
	rangeCircle.setRadius(range);
	rangeCircle.setOutlineThickness(2);
	rangeCircle.setFillColor(sf::Color(0, 0, 255, 100));
}

NormalTower::~NormalTower()
{
}

void Tower::sellTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(int(NORMAL_TOWER_PRICE * INCOME_RATE));
}

void NormalTower::doAttack() 
{
	attack.setDamage(damage);
	attack.resolve();
}