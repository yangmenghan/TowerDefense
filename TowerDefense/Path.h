#pragma once
#include "Tile.h"
#include <SFML\Graphics.hpp>

using namespace std;

class Path
{
private:
	vector<shared_ptr<Tile>> path;
	
public:
	//! A function to draw the path
	/*!
	\ param w is a game window
	*/
	void draw(sf::RenderWindow& w);


	//! A constructor
	/*!
	constructor with argument
	*/
	Path(vector<shared_ptr<Tile>>);	

	//! A constructor
	/*!
	constructor by default
	*/
	Path();		

	//! A function without arguments and return a vector of tiles which represent the path
	/*!
	\ return the path
	*/
	vector<shared_ptr<Tile>> getPath();					
};
