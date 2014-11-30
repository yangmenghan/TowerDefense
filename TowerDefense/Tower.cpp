#include "Tower.h"
#include "Player.h"
#include "LevelManager.h"
#include "NormalAttack.h"

Tower::Tower(Tile &mTile)
{
	level = 1;
	tile = mTile;
	attack = make_shared<NormalAttack>();
	attack->setCenter(tile.getPosition());

	speed = TOWER_SPEED;
}


Tower::~Tower()
{
}

float Tower::getDamage()
{
	return damage[level - 1];
}

int Tower::getPrice()
{
	return price;
}

int Tower::getLevel()
{
	return level;
}

float Tower::getRange()
{
	return range[level - 1];
}

void Tower::setDamage(float mDamage)
{
	damage[level - 1] = mDamage;
}

void Tower::setPrice(int mPrice)
{
	price = mPrice;
}

void Tower::setLevel(int mLevel)
{
	level = mLevel;
}

void Tower::setRange(float mRange)
{
	range[level - 1] = mRange;
}




void Tower::upgradeTw()
{
	if (level < 3)
	{
		level++;
		speed -= 5;

		attack->setDamage(damage[level - 1]);
		attack->setSlowAmount(damage[level - 1]);
		attack->setSpeed(speed);
		attack->setRange(range[level - 1]);

		timer = speed;
	}
}

void Tower::downgradeTw()
{
	if (level > 0)
	{
		level--;
		
		if (level != 0)
		{
			speed += 5;
			attack->setDamage(damage[level - 1]);
			attack->setSlowAmount(damage[level - 1]);
			attack->setSpeed(speed);
			attack->setRange(range[level - 1]);

			timer = speed;
		}
	}
	if (level == 0)
		this->~Tower();//Delete this tower
}

void Tower::sellTw()
{
	LevelManager::getLevelManager()->getPlayer().manageMoney(income[level - 1]);
}


