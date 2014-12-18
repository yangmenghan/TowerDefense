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

		//startGame
		levelManager->startGame();

		enemy.setTile(field.getStartTile());
		enemy.updatePath();

		enemy_b.setTile(field.getStartTile());
		enemy_b.updatePath();

	}
	virtual void TearDown(){
		levelManager->stopGame();
		levelManager->kill();
	}

protected:
	EnemyTest() {}
	virtual ~EnemyTest() {}
};


TEST_F(EnemyTest, waves)
{
	EXPECT_EQ(WAVE_TOTAL, levelManager->getWaves().size());
	EXPECT_EQ(1, levelManager->getCurrentWaveNumber());
}


TEST_F(EnemyTest, spawnEnemy)
{
	Wave w = levelManager->getWaves().at(0);
	for (int i = 0; i <= 2 * WAVE_SPAWN_COOLDOWN + 2 * WAVE_SPAWN_PAUSE_COOLDOWN ; i++){
		w.spawnEnemy();
	}

	EXPECT_EQ(1, levelManager->getEnemies().size());

}


TEST_F(EnemyTest, nextWave)
{
	LevelManager* lm = levelManager;
	for (int i = 0; i <= WAVE_COOLDOWN; i++){
		lm->nextWave();
	}

	EXPECT_EQ(WAVE_TOTAL - 1, levelManager->getWaves().size());
}

/*
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
	EXPECT_LT(field.getStartTile()->getPosition().x, enemy.getPosition().x);
}

TEST_F(EnemyTest, BombExplosion)
{
	enemy_b.explode();
	EXPECT_TRUE(enemy_b.getTile()->isPolluted());
	EXPECT_LT(0,enemy_b.getTile()->getCooldown());
}

TEST_F(EnemyTest, succed)
{
	enemy.succed();
	EXPECT_EQ(INIT_HP-1, levelManager->getPlayer()->getHP());
}

TEST_F(EnemyTest, slow)
{
	enemy.slow(100);
	EXPECT_GT(NORMAL_ENEMY_SPEED, enemy.getSpeed());

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

