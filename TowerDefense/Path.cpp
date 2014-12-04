#include "Tile.h"
#include "Path.h"
#include <SFML\Graphics.hpp>
#include <vector>

using namespace std;

Path::Path(vector<Tile> a)
{
	path = a;
};
Path::Path()
{

};


void Path::draw(vector<Tile> path)
{
	for (int i = 0; i < path.size(); i++)
	{
		Tile tile = path[i];
		//change color  TODO

	};


};

vector<Tile> Path::getPath()
{
	return path;
};
	

