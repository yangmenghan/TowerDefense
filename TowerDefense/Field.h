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
//! The field of battle.
/*!
*/
class Field
{
private:
	int width;								
	int height;								
	int numTileHor;							
	int numTileVer;							
	bool isHovered;
	std::vector<shared_ptr<Tile>> tilesMap;	
	Tile startTile;							
	Tile endTile;							
	Tile currentTileAcitve;
	sf::FloatRect boundingBox;
	sf::Sprite sprite;

public:
	//!Default constructor.
	/*!
	*/
	Field();								
	//!Destructor.
	/*!
	*/
	~Field();												
	//!Get the tile with the number of tile.
	/*!
	\param n the number of the tile.
	\return Return the shared pointer of the tile.
	*/
	shared_ptr<Tile> getTile(int n);						
	//!Get the tile with its position. 
	/*!
	\param position : the postion of the tile in the form of (row,collon).
	\return Return the shared pointer of the tile.
	*/
	shared_ptr<Tile> getTile(sf::Vector2i position);	
	//!Get the start tile.
	/*!
	\return Return the shared pointer of the strat tile.
	\sa Tile.
	*/
	shared_ptr<Tile> getStartTile();					
	//!Get the end tile.
	/*!
	\return Return the shared pointer of the end tile.
	*/
	shared_ptr<Tile> getEndTile();						
	//! Get the sprite of the field.
	/*!
	\return The sprite.
	*/
	sf::Sprite getSprite();
	//! Set the sprite of field.
	/*!
	\param sprite : the sprite of the field.
	*/
	void setSprite(sf::Sprite sprite);
	//! Check if the tile is hovered.
	/*!
	\sa mouseHover(sf::RenderWindow& w).
	\return Return true if the tile is hovered.
	\sa checkHover().
	*/
	bool mouseHover(sf::RenderWindow& w);
	//! Check if the tile is hovered.
	/*!
	\return Return true if the tile is hovered.
	*/
	bool checkHover();
	//! Resolve the mouse event.
	/*!
	Call all the tiles to resolve the event.
	\param event : the mouse enevt.
	*/
	void resolveEvent(sf::Event event);
	//! Draw the field and all the tiles.
	/*!
	\param w the RenderWindow of the game.
	*/
	void draw(sf::RenderWindow&);
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