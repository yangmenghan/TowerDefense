#include "Tile.h"
#include "Path.h"
#include <SFML\Graphics.hpp>
#include <vector>

using namespace std;

Path::Path(vector<shared_ptr<Tile>> a)
{
	path = a;
};
Path::Path()
{

};


void Path::draw()
{
	for (int i = 0; i < path.size(); i++)
	{
		
		//change color  TODO 
		//path[i] - >;

	};


};

vector<shared_ptr<Tile>> Path::getPath()
{
	return path;
};
	

