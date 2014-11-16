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
	Tile* getStartTile();
	Tile* getEndTile();

	//Setters
	//void setWidth(int);
	//void setHeight(int);
	//void setMap();

	//Functions
	void draw();
	Path computePath(Tile, Tile);  // compute the path of all the enemies
	bool tryCross(Tile, Tile);  // to know if all the enemies can go to the destination
	int timeCross(int, int);  // nomber of tile until the destination
};