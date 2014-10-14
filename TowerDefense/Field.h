#pragma once
#include <map>
#include <SFML\Graphics.hpp>
#include "Tile.h"
#include "Path.h"

class Field
{
private:
	int width;
	int height;
	map<Tile,int> map;
	Tile* startTile;
	Tile* endTile;
public:
	//Constructors and destroyers
	Field();
	~Field();
	
	//Getters
	int getWidth();
	int getHeight();

	//Setters
	void setWidth(int);
	void setHeight(int);
	void setMap();

	//Functions
	void draw();
	Path computePath(Tile, Tile);//startTile,endTile
	bool tryCross(Tile);//startTile
};