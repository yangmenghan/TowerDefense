#pragma once
#include <map>
#include <SFML\Graphics.hpp>

class Field
{
private:
	int width;
	int height;
	map<Tile,int> map;
	Tile startTile;
	Tile endTile;
public:
	Field();
	~Field();
	void draw();
	path computePath(Tile, Tile);//startTile,endTile
	bool tryCross(Tile);//startTile
};