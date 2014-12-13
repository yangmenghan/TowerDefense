#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <string>
#include "Menu.h"
#include "Button.h"




using namespace std;

class Tile;
//! A menu to build a tower.
/*!
Appeared when click on an empty tile.
*/
class BuildMenu 
	: public Menu
{
private: 
	shared_ptr<Tile> tile;				
	Button basicTwButton;				
	Button slowTwButton;					
	Button moneyTwButton;				
	Button sunTwButton;						
	

	std::string fontAddress;
	sf::Font font;
	sf::Text basicPrice; 
	sf::Text slowPrice;
	sf::Text moneyPrice;
	sf::Text sunPrice;
public:
	//!Default constructor.
	/*!
	*/
	BuildMenu();							
	//!Construct a build menu with a tile. 
	/*!
	\param tile : the tile where opens the build menu.
	*/										
	BuildMenu(shared_ptr<Tile> tile);
	//!Destructor.
	/*!
	*/
	~BuildMenu();							
	//!Get the tile where build the tower.
	/*!
	\return Return the shared pointer of the tile.
	*/
	shared_ptr<Tile> getTile();				
	//!Buy and build a normal tower.
	/*!
	*/
	void buyBasicTw();						
	//!Buy and build a slow tower.
	/*!
	*/
	void buySlowTw();						
	//!Buy and build a money tower.
	/*!
	*/
	void buyMoneyTw();						
	//!Buy and build a sun tower.
	/*!
	*/
	void buySunTw(); 						
	//! Resolve the mouse event.
	/*!
	Build a tower when click on the button or close the menu when click outside.
	*/
	void resolveEvent(sf::Event event);
	//!Draw the build menu.
	/*!
	Draw the menu and show the money of each tower.
	*/
	void draw(sf::RenderWindow&);			
	//!Close the menu.
	/*!
	*/
	void close();							
};