#pragma once
#include <map>
#include <vector>
#include <memory>
#include <SFML\Graphics.hpp>
#include "Tile.h"
#include "Path.h"
#include "string.h"

class Field
{
private:
	int width;
	int height;
	int numTileHor;
	int numTileVer;
	std::vector<Tile> tilesMap;
	Tile startTile;
	Tile endTile;

public:
	//Constructors and destroyers
	Field();
	~Field();
	
	//Getters
	int getWidth();
	int getHeight();
	int getNumTileVer();
	int getNumTileHor();
	Tile* getTile(int);
	Tile* getTile(sf::Vector2i position);

	//Setters
	//void setWidth(int);
	//void setHeight(int);
	//void setMap();

	//Functions
	void draw();
	Path computePath(Tile, Tile);
	bool tryCross(Tile, Tile);
	int Field::tempCross(int, int);
};