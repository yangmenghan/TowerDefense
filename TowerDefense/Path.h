#pragma once
#include "Tile.h"
#include <SFML\Graphics.hpp>

using namespace std;

class Path
{
private:
	vector<shared_ptr<Tile>> path;
	
public:
	void draw();				//draw path by changing color
	Path(vector<shared_ptr<Tile>>);						//constructor
	Path();									//constructor
	vector<shared_ptr<Tile>> getPath();					//provide path
};
