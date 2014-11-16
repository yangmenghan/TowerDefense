#pragma once
#include <map>
#include <vector>
#include <memory>
#include <SFML\Graphics.hpp>
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
	std::vector<Tile> tilesMap;				//The vector of tiles in this field.
	Tile startTile;							//The tile where enter the enemies.
	Tile endTile;							//The tile in the end of the path of enemies.
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
	Tile* getTile(int);						//Get the tile with the number of tile.
	Tile* getTile(sf::Vector2i position);	//Get the tile with its position. 
	Tile* getStartTile();					//Get the starttile.
	Tile* getEndTile();						//Get the end tile.
	sf::Sprite getSprite();

	//Setters
	void setSprite(sf::Sprite);

	//Functions
	bool mouseHover();
	bool mouseClicking(sf::Event);
	bool mouseClick(sf::Event);
	void draw(sf::RenderWindow&);			//Draw.
	Path computePath(Tile, Tile);			//Compute the path of the enemenies
	bool tryCross(Tile, Tile); 
	int timeCross(int, int);
};