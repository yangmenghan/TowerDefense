#include"Field.h"

Field::Field()
{
	width = TILE_WIDTH * TILE_NUM_HOR;
	height = TILE_HEIGHT * TILE_NUM_VER;
	numTileHor = TILE_NUM_HOR;
	numTileVer = TILE_NUM_VER;

	for (int i = 0; i < TILE_NUM_HOR*TILE_NUM_VER; i++)
	{
		//Tile tile(i / TILE_NUM_HOR, i % TILE_NUM_HOR);
		//shared_ptr<Tile> pTile = make_shared<Tile>(tile);
		tilesMap.emplace_back(i / TILE_NUM_HOR, i % TILE_NUM_HOR);
	}

	startTile = tilesMap[NUM_START_TILE];
	endTile = tilesMap[NUM_END_TILE];
}

Field::~Field(){};

int Field::getWidth()
{
	return width;
}

int Field::getHeight()
{
	return height;
}

int Field::getNumTileHor()
{
	return numTileHor;
}

int Field::getNumTileVer()
{
	return numTileVer;
}

void Field::draw()
{
	//to do
}

Path Field::computePath(Tile _startTile, Tile _endTile)
{
	//To do
}

bool Field::tryCross(Tile _tile)
{
	//To do
}