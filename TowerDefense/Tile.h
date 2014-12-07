#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <memory>
#include <Vector>
#include "BuildMenu.h"
#include "TowerMenu.h"
#include "MenuManager.h"

class Tower;

class Tile
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
public:
	//Constructors and destroyers
	Tile();										//Default constructor. 
	Tile(int, int); 							//Constructs the container with the position of tile.
	~Tile();									//Destructor.

	//Getters
	sf::Vector2i getPosition();					//Get the position of tile.
	sf::Vector2i getPositionPixel();			//Get the position of the pixel topleft of the tile.
	shared_ptr<Tower>  getTower();				//Get the pointer of the tower in this tile.
	int getCooldowm();							//Get the time left for the tower to return normal.
	vector<shared_ptr<Tile>> getNeighbor(int);	//get all the tiles near this tile.
												//The distanse may be 1,2,3.
	sf::Sprite getSprite();


	//Setters
	void setPosition(sf::Vector2i);				//Set the position of this tile.
	void setTower(shared_ptr<Tower>);			//Build a tower in this tile.
	void setCooldown(int);						//Set the time of cooldown for the tower in this tile.
	void setSprite(sf::Sprite);

	//Functions	
	void mouseHover(sf::RenderWindow& w);
	bool checkHover();
	bool checkClick();
	void resolveEvent(sf::Event );
	bool isPolluted();							//Determine if the tower in this tile is polluted by enemy.
	bool hasTower();							//Determine if there is a tower built in this tile.
	shared_ptr<BuildMenu> openBuildMenu();		//Open the menu for build a tower.
	shared_ptr<TowerMenu> openTowerMenu();		//Open the menu for upgrade or sell a menu.
	void draw(sf::RenderWindow&);
	void spriteUpdate(int);
};