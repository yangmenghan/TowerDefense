#pragma once
#include <map>
#include <memory>
#include <SFML\Graphics.hpp>
#include "Tile.h"
#include "Path.h"

class Field
{
private:
	int width;
	int height;
	int numTileHor;
	int numTileVer;
	map<shared_ptr<Tile>,int> tilesMap;
	shared_ptr<Tile> startTile;
	shared_ptr<Tile> endTile;
public:
	//Constructors and destroyers
	Field();
	~Field();
	
	//Getters
	int getWidth();
	int getHeight();
	int getNumTileVer();
	int getNumTileHor();

	//Setters
	void setWidth(int);
	void setHeight(int);
	void setMap();

	//Functions
	void draw();
	Path computePath(shared_ptr<Tile>, shared_ptr<Tile>);//startTile,endTile
	bool tryCross(shared_ptr<Tile>);//startTile
};