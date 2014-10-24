#include "Tile.h";
#include "Path.h";
#include <SFML\Graphics.hpp>
#include <vector>

using namespace std;

Path::Path(vector<Tile> a)
{
	path = a;
};
Path::Path()
{
	vector<Tile> b;
	path = b;
};


void Path::draw(vector<Tile> path)
{
	for (int i = 0; i < path.size(); i++)
	{
		Tile tile = path[i];

	};


};
	

