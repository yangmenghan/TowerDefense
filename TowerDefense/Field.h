#pragma once
#include <map>
#include <vector>
#include <memory>
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include "Tile.h"
#include "Path.h"
#include "string.h"
#include "Config.h"
#include "Enemy.h"

class Field
{
private:
	int width;								//The width of the field.
	int height;								//The height of the heignt.
	int numTileHor;							//The number of tiles in a row.
	int numTileVer;							//The number of tiles in a colonne.
	bool isHovered;
	std::vector<shared_ptr<Tile>> tilesMap;	//The vector of tiles in this field.
	Tile startTile;							//The tile where enter the enemies.
	Tile endTile;							//The tile in the end of the path of enemies.
	Tile currentTileAcitve;
	sf::FloatRect boundingBox;
	sf::Sprite sprite;

public:
	//Constructors and destroyers
	Field();								//Default constructor.
	~Field();								//Destructor.
	
	//Getters
	int getWidth();							//Get the width of this field.
	int getHeight();						//Get the height of this field.
	int getNumTileVer();					//Get the nomber of tiles in a colonne.
	int getNumTileHor();					//Get the nomber of tiles in a row.
	std::vector<shared_ptr<Tile>> getAllTiles();
	shared_ptr<Tile> getTile(int);						//Get the tile with the number of tile.
	shared_ptr<Tile> getTile(sf::Vector2i position);	//Get the tile with its position. 
	shared_ptr<Tile> getStartTile();					//Get the starttile.
	shared_ptr<Tile> getEndTile();						//Get the end tile.
	sf::Sprite getSprite();

	//Setters
	void setSprite(sf::Sprite);

	//Functions
	bool mouseHover(sf::RenderWindow&);
	bool checkHover();
	//bool mouseClicking(sf::Event);
	//bool mouseClick(sf::Event);
	void resolveEvent(sf::Event);
	void draw(sf::RenderWindow&);			//Draw
	
	//! A function with 2 arguments and returns a path which is a vector of tiles
	/*!
	\param tile1 is the start tile of the path
	\param tile2 is the end tile of the path
	\return The path computed
	*/
	Path computePath(shared_ptr<Tile> tile1, shared_ptr<Tile> tile2);	

	//! A function with 2 arguments and returns a boolean which represent if there existe a path
	/*!
	\param tile1 is the start tile of the path
	\param tile2 is the end tile of the path
	\return If there existe a path
	*/
	bool tryCross(shared_ptr<Tile> tile1, shared_ptr<Tile> tile2);
};