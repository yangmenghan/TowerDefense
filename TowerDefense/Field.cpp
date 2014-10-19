#include"Field.h"

Field::Field()
{
	width = TILE_WIDTH * TILE_NUM_HOR;
	height = TILE_HEIGHT * TILE_NUM_VER;
	numTileHor = TILE_NUM_HOR;
	numTileVer = TILE_NUM_VER;

	for (int i = 0; i < TILE_NUM_HOR*TILE_NUM_VER; i++)
	{
		Tile tile(i / TILE_NUM_HOR, i % TILE_NUM_HOR);
		shared_ptr<Tile> pTile = make_shared<Tile>(tile);
		tilesMap.insert();
	}
}