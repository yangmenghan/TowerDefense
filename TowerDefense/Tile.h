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
//! Tile
/*!
*/
class Tile : public enable_shared_from_this<Tile>
{
private:
	sf::Vector2i positionPixel;					//Positon of the pixel in topleft point of tile.
	sf::Vector2i position; 						//Position of tile (row,colonne).
	int width;									//The width of every tile.
	int height;									//The height of every tile.
	int cooldown;								//Time left for the tower to return normal.The defaut value is 0s. 
	shared_ptr<Tower> tower;					//The tower built in this tile.
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
	\param y the collone of the tile.
	*/
	Tile(int x, int y); 							
	//! Destructor.
	/*!
	*/
	~Tile();									
	//! Get the position of tile.
	/*!
	\return The position in forme sf::Vector2i.(x,y) is row and collone of the tile.
	*/
	sf::Vector2i getPosition();					
	//! Get the position of the pixel of topleft of the tile.
	/*!
	\return The position in forme sf::Vector2i.
	*/
	sf::Vector2i getPositionPixel();			
	//! Get the pointer of the tower in this tile.
	/*!
	\return A shared pointer of the tower in this tile.
	*/
	shared_ptr<Tower>  getTower();				
	//! Get the time left for the tower to return normal.
	/*!
	\return An integer which means the time left for the tile to become nomal.  
	*/
	int getCooldown();							
	//! Get all the tiles near this tile.
	/*!
	\param range is the distance entre two tiles. It can be 1, 2, 3.
	\return A vactor contains all the shared pointers of the tile near this tile.
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
	//! Build a tower in this tile.
	/*!
	\param tower is the tower built in this tile.
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
	//! 
	/*!
	\param w the RenderWindow of the game.
	*/
	void mouseHover(sf::RenderWindow& w);
	//! 
	/*!
	*/
	bool checkHover();
	//! 
	/*!
	*/
	bool checkClick();
	//! 
	/*!
	*/
	void resolveEvent(sf::Event );
	//! Determine if the tower in this tile is polluted by enemy.
	/*!
	\return
	*/
	bool isPolluted();							
	//! Determine if there is a tower built in this tile.
	/*!
	\return
	*/
	bool hasTower();							
	//! Open the menu for build a tower.
	/*!
	\return
	*/
	shared_ptr<BuildMenu> openBuildMenu();		
	//! Open the menu for upgrade or sell a menu.
	/*!
	*/
	shared_ptr<TowerMenu> openTowerMenu();		
	//! 
	/*!
	\return
	*/
	void draw(sf::RenderWindow&);
	//! 
	/*!
	\return
	*/
	void spriteUpdate(int);
	//! 
	/*!
	\return
	*/
	bool hasEnemy();
};