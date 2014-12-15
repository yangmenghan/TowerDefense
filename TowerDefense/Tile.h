#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <memory>
#include <Vector>
#include "BuildMenu.h"
#include "TowerMenu.h"
#include "MenuManager.h"

using namespace std;

class Tower;
//! A unit in the field.
/*!
*/
class Tile : public enable_shared_from_this<Tile>
{
private:
	sf::Vector2i positionPixel;					
	sf::Vector2i position; 						
	int width;									
	int height;									
	int cooldown;								
	shared_ptr<Tower> tower;					
	sf::IntRect boundingBox;
	sf::Sprite sprite;
	sf::Texture texture;
	int currentSprite;
	bool isHovered;
	bool isClicked;
	bool isClicking;
	bool hasTw;
public:
	//! Default constructor. 
	/*!
	*/
	Tile();

	//! Construct the tile with the position of tile.
	/*!
	\param x the row of the tile.
	\param y the column of the tile.
	*/
	Tile(int x, int y); 		

	//! Destructor.
	/*!
	*/
	~Tile();				

	//! Get the position of tile.
	/*!
	\return The position in the form of a sf::Vector2i.(x,y) (row and column of the tile)
	*/
	sf::Vector2i getPosition();		

	//! Get the position of the pixel of topleft of the tile.
	/*!
	\return The position in the form sf::Vector2i.
	*/
	sf::Vector2i getPositionPixel();	

	//! Get the pointer of the tower in this tile.
	/*!
	\return A shared pointer of the tower in this tile.
	*/
	shared_ptr<Tower>  getTower();		

	//! Get the time left for the tower to return normal.
	/*!
	\return an integer which is the time left for the tile to become nomal.  
	*/
	int getCooldown();	

	//! Get all the tiles near this tile.
	/*!
	\param range is the distance between two tiles. It can be 1, 2, 3.
	\return A vector contains all the shared pointers of the tile near this tile.
	*/
	vector<shared_ptr<Tile>> getNeighbor(int range);	

	//! Get the sprite of the tile.
	/*!
	\return The sprite.
	*/
	sf::Sprite getSprite();

	//! Set the position of this tile.
	/*!
	\param pos is the postion that will be set to the tile.
	*/
	void setPosition(sf::Vector2i pos);

	//! Build a tower on this tile.
	/*!
	\param tower is the tower to be built on this tile.
	*/
	void setTower(shared_ptr<Tower> tower);			

	//! Set the time of cooldown for the tower in this tile.
	/*!
	Set the time of cooldown for the tower in this tile and change the tile into the polluted sprite.
	*/
	void setCooldown();	

	//! Set the sprite of tile.
	/*!
	\param sprite is set to be the sprite of this tile. 
	*/
	void setSprite(sf::Sprite sprite);

	//! Deal with the hovering case of tile.
	/*!
	Change the sprite when the mouse is hovering over this tile. If there is a tower built on the tile, it will show the range of the tower when the tile is hovering.
	\param w the RenderWindow of the game.
	*/
	void mouseHover(sf::RenderWindow& w);

	//! Check if the tile is hovered.
	/*!
	\return Return true if the tile is hovered.
	*/
	bool checkHover();

	//! Check if the tile is clicked.
	/*!
	\return Return true if the mouse click on the tile.
	*/
	bool checkClick();

	//! Resolve the mouse event on the tile. 
	/*!
	If the tile is polluted by enemies, do nothing.
	Else we can build, upgrade or sell a tower on this tile with the  mouse event.
	\param event is the mouse event that is resolved in this function.
	*/
	void resolveEvent(sf::Event event);

	//! Determine if the tower in this tile is polluted by enemy.
	/*!
	\return Return true if the tile is polluted by enemy.
	*/
	bool isPolluted();		

	//! Determine if there is a tower built in this tile.
	/*!
	\return Return true if the tile has a tower.
	*/
	bool hasTower();	

	//! Open the menu for build a tower.
	/*!
	\return Return the shared pointer of the menu for building a tower.
	*/
	shared_ptr<BuildMenu> openBuildMenu();		

	//! Open the menu for upgrade or sell a tower.
	/*!
	\return Return the shared pointer of the menu for upgrading or selling the tower.
	*/
	shared_ptr<TowerMenu> openTowerMenu();

	//! Draw the tile.
	/*!
	Draw tile and show the state of the tile(polluted, hovered).
	\param w the RenderWindow of the game.
	*/
	void draw(sf::RenderWindow& w);

	//! Update the sprite of tile.
	/*!
	\param i : Change to the sprite i.
	*/
	void spriteUpdate(int i);

	//! Determine if there is an enemy on this tile.
	/*!
	\return Return true if there is an enemy on this tile.Else return false.
	*/
	bool hasEnemy();
};