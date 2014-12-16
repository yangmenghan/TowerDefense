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

TEST(NormalEnemy, construction)
{
	NormalEnemy enemy;
	EXPECT_EQ(NORMAL_ENEMY_HP, enemy.getHP());
}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	getchar();
	return 0;
}