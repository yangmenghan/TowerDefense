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


void Path::draw(sf::RenderWindow &w)
{
	sf::CircleShape shape(4);  
	shape.setFillColor(sf::Color(100, 250, 50));
	
	for (int i = 0; i < path.size(); i++)
	{
		//draw circle in the center 
		shared_ptr<Tile> tile = path[i];
		sf::Vector2i vec = tile->getPositionPixel();
		sf::Vector2f vec1;
		vec1.x =vec.x + 21;
		vec1.y =vec.y + 21;
		shape.setPosition(vec1);
		w.draw(shape);

	};


};

vector<shared_ptr<Tile>> Path::getPath()
{
	return path;
};
	

