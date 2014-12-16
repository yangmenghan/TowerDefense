#include <gtest/gtest.h>
#include "Tile.h"
#include "Field.h"
#include "BuildMenu.h"
#include "TowerMenu.h"
#include "Tower.h"
#include "Config.h"

using namespace std;

/*TEST(Tile, isPolluted)
{
	EXPECT_EQ();
}*/

TEST(Tile,construction)
{
	Tile tile;
	EXPECT_EQ(0,tile.getCooldown());
}

TEST(Field, construction)
{
	Field field;
	EXPECT_FALSE(field.getTile(NUM_END_TILE)->isPolluted());
}

TEST(BuildMenu, construction)
{
	auto pTile = make_shared<Tile>(0, 0);
	BuildMenu buildMenu(pTile);
	buildMenu.buyBasicTw();
	EXPECT_TRUE(pTile->hasTower());
}

TEST(TowerMenu, construction)
{
	auto pTile = make_shared<Tile>(0,0);
	BuildMenu buildMenu(pTile);
	buildMenu.buySunTw();
	TowerMenu towerMenu(pTile);
	pTile->getTower()->sellTw();
	EXPECT_FALSE(pTile->hasTower());
}

int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);
	
	RUN_ALL_TESTS();

	string m3;
	cout << "fin des tests unitaires";
	getline(cin, m3);

	return 1;
}

/*
int Foo(int a, int b)
{
if (a == 0 || b == 0)
{
throw "don't do that";
}
int c = a % b;
if (c == 0)
return b;
return Foo(b, c);
}

TEST(FooTest, HandleNoneZeroInput)
{
EXPECT_EQ(2, Foo(4, 10));
EXPECT_EQ(3, Foo(30, 18));
}
*/