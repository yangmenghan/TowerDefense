#pragma once
#include "Tile.h"
#include <SFML\Graphics.hpp>

using namespace std;

class Path
{
private:
	vector<Tile> path;
	
public:
	void draw(vector<Tile>);				//draw path by changing color
	Path(vector<Tile>);						//constructor
	Path();									//constructor
	vector<Tile> getPath();					//provide path
};
