#include <gtest/gtest.h>
#include "Tower.h"
#include "NormalTower.h"
#include "SlowTower.h"
#include "MoneyTower.h"
#include "SunTower.h"
#include "NormalEnemy.h"

using namespace std;

TEST(Tower, construction)
{
	shared_ptr<Tile> pTile = make_shared<Tile>(1, 1);
	NormalTower tower(pTile);
	EXPECT_EQ(1,tower.getLevel() );
	EXPECT_EQ(NORMAL_TOWER_DAMAGE[0],tower.getDamage());
	EXPECT_EQ(NORMAL_TOWER_INCOME[0], tower.getIncome());
	EXPECT_EQ(NORMAL_TOWER_PRICE, tower.getPrice());
	EXPECT_EQ(NORMAL_TOWER_RANGE[0], tower.getRange());
	EXPECT_EQ(TILE_WIDTH, tower.getSize().x);
	EXPECT_EQ(TILE_HEIGHT, tower.getSize().y);
	EXPECT_EQ(tower.getTile()->getPositionPixel().x + 25, tower.getPosition().x);
	EXPECT_EQ(tower.getTile()->getPositionPixel().y + 25, tower.getPosition().y);
	EXPECT_EQ(NORMAL_TOWER_SPEED[0], tower.getSpeed());
}
TEST(Tower, attackConstruction)
{
	shared_ptr<Tile> pTile = make_shared<Tile>(1, 1);
	NormalTower tower(pTile);

	EXPECT_EQ(tower.getPosition().x, tower.getAttack()->getCenter().x);
	EXPECT_EQ(tower.getPosition().y, tower.getAttack()->getCenter().y);
	EXPECT_EQ(tower.getDamage(), tower.getAttack()->getDamage());
	EXPECT_EQ(0, tower.getAttack()->getSlowAmount());
}

TEST(Tower, grade)
{
	shared_ptr<Tile> pTile = make_shared<Tile>(1, 1);
	NormalTower tower(pTile);
	
	for (int i = 0; i < 3; i++)
	{
		EXPECT_EQ(i + 1, tower.getLevel());
		EXPECT_EQ(NORMAL_TOWER_DAMAGE[i], tower.getDamage());
		EXPECT_EQ(NORMAL_TOWER_INCOME[i], tower.getIncome());
		EXPECT_EQ(NORMAL_TOWER_RANGE[i], tower.getRange());
		EXPECT_EQ(NORMAL_TOWER_SPEED[i], tower.getSpeed());
		EXPECT_EQ(tower.getDamage(), tower.getAttack()->getDamage());
		EXPECT_EQ(0, tower.getAttack()->getSlowAmount());
		tower.upgradeTw();
	}
	EXPECT_EQ(3, tower.getLevel());
	EXPECT_EQ(NORMAL_TOWER_DAMAGE[2], tower.getDamage());
	EXPECT_EQ(NORMAL_TOWER_INCOME[2], tower.getIncome());
	EXPECT_EQ(NORMAL_TOWER_RANGE[2], tower.getRange());
	EXPECT_EQ(NORMAL_TOWER_SPEED[2], tower.getSpeed());
	EXPECT_EQ(tower.getDamage(), tower.getAttack()->getDamage());
	EXPECT_EQ(0, tower.getAttack()->getSlowAmount());
	
	tower.downgradeTw();
	EXPECT_EQ(0, tower.getLevel());
}

TEST(Tower, sellTower)
{
	shared_ptr<Tile> pTile = make_shared<Tile>(1, 1);
	NormalTower tower(pTile);
	int originMoney = LevelManager::getLevelManager()->getPlayer()->getMoney();
	int income = tower.getIncome();
	tower.sellTw();
	EXPECT_EQ(originMoney + income, LevelManager::getLevelManager()->getPlayer()->getMoney());
	EXPECT_FALSE(pTile == NULL);
}

TEST(MoneyTower, generateMoney)
{
	shared_ptr<Tile> pTile = make_shared<Tile>(1, 1);
	MoneyTower tower(pTile);
	int originMoney = LevelManager::getLevelManager()->getPlayer()->getMoney();
	tower.setTimer(0);
	tower.generateMoney();
	EXPECT_EQ(originMoney + MONEY_TOWER_GENERATION_UNIT[0], LevelManager::getLevelManager()->getPlayer()->getMoney());
	EXPECT_EQ(tower.getSpeed(), tower.getTimer());
}

TEST(Attack, setAttackRayAngle)
{
	shared_ptr<Enemy> target = make_shared<NormalEnemy>();
	shared_ptr<Tile> pTile = make_shared<Tile>(10, 5);
	NormalTower tower(pTile);

	target->setPosition(sf::Vector2i(tower.getPosition().x + 100, tower.getPosition().y ));
	tower.getAttack()->setAttackRayAngle(target);
	EXPECT_FALSE(tower.getAttack()->getAttackRay().getRotation() == 0);

	target->setPosition(sf::Vector2i(tower.getPosition().x + 100, tower.getPosition().y + 50));
	tower.getAttack()->setAttackRayAngle(target);
	EXPECT_FALSE(tower.getAttack()->getAttackRay().getRotation() > 0 &&
				tower.getAttack()->getAttackRay().getRotation() < 90);

	target->setPosition(sf::Vector2i(tower.getPosition().x, tower.getPosition().y + 100));
	tower.getAttack()->setAttackRayAngle(target);
	EXPECT_FALSE(tower.getAttack()->getAttackRay().getRotation() == 90 );

	target->setPosition(sf::Vector2i(tower.getPosition().x - 100, tower.getPosition().y + 100));
	tower.getAttack()->setAttackRayAngle(target);
	EXPECT_FALSE(tower.getAttack()->getAttackRay().getRotation() > 90 &&
		tower.getAttack()->getAttackRay().getRotation() < 180);

	target->setPosition(sf::Vector2i(tower.getPosition().x - 100, tower.getPosition().y));
	tower.getAttack()->setAttackRayAngle(target);
	EXPECT_FALSE(tower.getAttack()->getAttackRay().getRotation() == 180);

	target->setPosition(sf::Vector2i(tower.getPosition().x - 100, tower.getPosition().y - 100));
	tower.getAttack()->setAttackRayAngle(target);
	EXPECT_FALSE(tower.getAttack()->getAttackRay().getRotation() > 180 &&
		tower.getAttack()->getAttackRay().getRotation() < 270);

	target->setPosition(sf::Vector2i(tower.getPosition().x, tower.getPosition().y - 100));
	tower.getAttack()->setAttackRayAngle(target);
	EXPECT_FALSE(tower.getAttack()->getAttackRay().getRotation() == 270);

	target->setPosition(sf::Vector2i(tower.getPosition().x + 100, tower.getPosition().y - 100));
	tower.getAttack()->setAttackRayAngle(target);
	EXPECT_FALSE(tower.getAttack()->getAttackRay().getRotation() > 270 &&
		tower.getAttack()->getAttackRay().getRotation() < 360);
}

TEST(Attack, getTarget)
{
	shared_ptr<Tile> pTile = make_shared<Tile>(10, 5);
	NormalTower tower(pTile);
	shared_ptr<Enemy> enemy = make_shared<NormalEnemy>();
	enemy->setPosition(sf::Vector2i(tower.getPosition().x + tower.getRange() - 1, tower.getPosition().y));
	LevelManager::getLevelManager()->addEnemy(enemy);

	shared_ptr<Enemy> target = tower.getAttack()->getTarget();
	EXPECT_FALSE(target);
}

TEST(AreaAttack, getTarget)
{

}
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	getchar();
	return 0;
}