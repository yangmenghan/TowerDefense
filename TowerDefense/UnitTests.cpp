#include <gtest/gtest.h>
#include "Field.h"
#include "Enemy.h"
#include "NormalEnemy.h"
#include "ToughEnemy.h"
#include "FastEnemy.h"
#include "BombEnemy.h"
#include "Config.h"

using namespace std;

/* Example for unit tests


TEST(fraction, addition2)
{
	Fraction f1(2, 3);
	Fraction f2(1, 3);
	Fraction f3 = f1 + f2;
	EXPECT_EQ(1, f3);
	EXPECT_EQ(1, f3.numerateur());
}


*/

TEST(Enemy, construction)
{
	Field f;
	NormalEnemy enemy;
	EXPECT_EQ(NORMAL_ENEMY_HP, enemy.getHP());

	enemy.setTile(f.getStartTile());
	EXPECT_EQ(f.getStartTile()->getPosition(), enemy.getTile()->getPosition());
}

TEST(Enemy, move){
	Field f;
	NormalEnemy enemy;
	enemy.setTile(f.getStartTile());
	enemy.updatePath();
	enemy.move();
	EXPECT_GT(f.getStartTile()->getPosition().x,enemy.getPosition().x);

}

TEST(BombEnemy, explode){
	Field f;
	BombEnemy b;
	b.takeDamage(BOMB_ENEMY_HP * 4 / 5);
	b.move();
}

int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	string m3;
	cout << "fin des tests unitaires";
	getline(cin, m3);
}