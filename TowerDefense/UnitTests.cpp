#include <gtest/gtest.h>
#include "Field.h"
#include "Enemy.h"
#include "NormalEnemy.h"
#include "ToughEnemy.h"
#include "FastEnemy.h"
#include "BombEnemy.h"
#include "Config.h"
#include "LevelManager.h"

using namespace std;

class EnemyTest : public ::testing::Test {
public:
	NormalEnemy enemy;
	BombEnemy enemy_b;
	FastEnemy enemy_f;
	ToughEnemy enemy_t;
	Path init_path;
	LevelManager* levelManager = LevelManager::getLevelManager();
	Field field = levelManager->getField();

	virtual void SetUp(){

		enemy.setTile(field.getStartTile());
		enemy.updatePath();

		//startGame
		levelManager->startGame();

		//create init path
		vector<shared_ptr<Tile>> a;
		a.push_back(field.getTile(80));
		a.push_back(field.getTile(81));
		a.push_back(field.getTile(82));
		a.push_back(field.getTile(83));
		a.push_back(field.getTile(84));
		a.push_back(field.getTile(85));
		a.push_back(field.getTile(86));
		a.push_back(field.getTile(87));
		a.push_back(field.getTile(88));
		a.push_back(field.getTile(89));
		a.push_back(field.getTile(90));
		a.push_back(field.getTile(91));
		a.push_back(field.getTile(92));
		a.push_back(field.getTile(93));
		a.push_back(field.getTile(94));
		a.push_back(field.getTile(95));
		a.push_back(field.getTile(96));
		a.push_back(field.getTile(97));
		a.push_back(field.getTile(98));
		a.push_back(field.getTile(99));
		init_path = Path(a);

		//create test path
	}
	virtual void TearDown(){}

protected:

	EnemyTest() {
		
	}

	virtual ~EnemyTest() {
	}


};

/*
TEST_F(EnemyTest, waves)
{
	//EXPECT_EQ(WAVE_TOTAL);
}

TEST_F(EnemyTest, spawnEnemy)
{
	//EXPECT_EQ(NORMAL_ENEMY_HP, enemy.getHP());
}

TEST_F(EnemyTest, nextWave)
{
	//EXPECT_EQ(NORMAL_ENEMY_HP, enemy.getHP());
}

TEST_F(EnemyTest, addEnemy)
{
	//EXPECT_EQ(NORMAL_ENEMY_HP, enemy.getHP());
}

TEST_F(EnemyTest, removeEnemy)
{
	//LevelManager->removeEnemy(enemy);
	//EXPECT_EQ(NORMAL_ENEMY_HP, enemy.getHP());
}*/

TEST_F(EnemyTest, construction)
{
	EXPECT_EQ(NORMAL_ENEMY_HP, enemy.getHP());
	EXPECT_EQ(BOMB_ENEMY_HP, enemy_b.getHP());
	EXPECT_EQ(FAST_ENEMY_HP, enemy_f.getHP());
	EXPECT_EQ(TOUGH_ENEMY_HP, enemy_t.getHP());
	
}

TEST_F(EnemyTest, setTile)
{

	
	EXPECT_EQ(field.getStartTile()->getPosition().x, enemy.getTile()->getPosition().x);

	
	EXPECT_EQ(TILE_NUM_VER, enemy.getDistanceToTarget());

}


TEST_F(EnemyTest, move)
{
	enemy.move();
	EXPECT_NE(field.getStartTile()->getPosition().x, enemy.getPosition().x);
}

TEST_F(EnemyTest, BombExplosion)
{
	enemy_b.explode();
	EXPECT_TRUE(enemy_b.getTile()->isPolluted());

	//EXPECT_EQ(NORMAL_ENEMY_HP, enemy.getHP());
}

TEST_F(EnemyTest, succed)
{
	enemy.succed();
	EXPECT_EQ(INIT_HP-1, levelManager->getPlayer()->getHP());
}

TEST_F(EnemyTest, slow)
{
	enemy.slow(100);
	EXPECT_LT(NORMAL_ENEMY_SPEED, enemy.getSpeed());

	enemy.move();
	EXPECT_EQ(99,enemy.getSlowTime());
}

TEST_F(EnemyTest, unSlow)
{
	for (int i = 0; i < 99; i++){
		enemy.move();
	}
	EXPECT_EQ(NORMAL_ENEMY_SPEED, enemy.getSpeed());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	getchar();
	return 0;
}

