#include <gtest/gtest.h>
#include "Tile.h"
#include "Field.h"
#include "BuildMenu.h"
#include "TowerMenu.h"
#include "Tower.h"
#include "Config.h"

using namespace std;

TEST(Tile,construction)
{
	auto tile=make_shared<Tile>(0,0);
	EXPECT_EQ(0,tile->getCooldown());
	EXPECT_EQ(sf::Vector2i(0,0), tile->getPosition());
	EXPECT_FALSE(tile->hasEnemy());
	EXPECT_FALSE(tile->hasTower());
	EXPECT_FALSE(tile->checkClick());
	EXPECT_FALSE(tile->checkHover());
	
}

TEST(Field, construction)
{
	Field field;
	EXPECT_EQ(sf::Vector2i(NUM_START_TILE % TILE_NUM_VER, NUM_START_TILE / TILE_NUM_VER), field.getStartTile()->getPosition());
	EXPECT_FALSE(field.getTile(NUM_START_TILE)->isPolluted());
	EXPECT_EQ(sf::Vector2i(NUM_END_TILE % TILE_NUM_VER, NUM_END_TILE / TILE_NUM_VER), field.getEndTile()->getPosition());
	EXPECT_FALSE(field.getTile(NUM_END_TILE)->isPolluted());
	std::vector<shared_ptr<Tile>> neighborTiles = field.getTile(sf::Vector2i(TILE_NUM_VER - 1, TILE_NUM_HOR - 1))->getNeighbor(1);
	EXPECT_EQ(4, neighborTiles.capacity());
	neighborTiles = field.getTile(sf::Vector2i(0, TILE_NUM_HOR - 1))->getNeighbor(3);
	EXPECT_EQ(19, neighborTiles.capacity());
	neighborTiles = field.getTile(sf::Vector2i(0, 8))->getNeighbor(1);
	EXPECT_EQ(6, neighborTiles.capacity());
	neighborTiles = field.getTile(sf::Vector2i(TILE_NUM_VER - 1, 5))->getNeighbor(1);
	EXPECT_EQ(6, neighborTiles.capacity());
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
	EXPECT_TRUE(pTile->hasTower());
	TowerMenu towerMenu(pTile);
	pTile->getTower()->sellTw();
	EXPECT_FALSE(pTile->hasTower());
}

int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);
	
	RUN_ALL_TESTS();

	string fin;
	cout << "Fin des tests unitaires.";
	getline(cin, fin);

	return 0;
}