#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <string>
#include "Button.h"
#include "Menu.h"

using namespace std;

class Tile;
//! Tower Menu class
/*!

*/
class TowerMenu : public Menu
{
private:
	//! Button 
	/*!
	The button is used to sell the tower in this tile.
	*/
	Button sellButton;							
	//! Button 
	/*!
	The button is used to upgrade the tower in this tile.
	*/
	Button upgradeButton;						
	//! Tile
	/*!
	The tile which opens the towermenu.
	*/
	shared_ptr<Tile> tile;						
	//! String
	/*!
	The name of the address of the font.
	*/
	std::string fontAddress;
	//! A font
	/*!

	*/
	sf::Font font;
	//!
	/*!

	*/
	sf::Text upGradePrice;
	//!
	/*!

	*/
	sf::Text sellPrice;

public:

	//! Default constructor.
	/*!
	Default constructor.
	*/
	TowerMenu::TowerMenu();						
	//! Construct the buildMenu at this tile. 
	/*!
	
	*/											
	TowerMenu(shared_ptr<Tile> t);
	//! Destructor
	/*!
	Destructor.
	*/
	~TowerMenu();								
	//! Get the tile which opens the towermenu.
	/*!
	
	*/
	shared_ptr<Tile> getTile();					
	//! Resolve all the events on this tile.
	/*!
	\param event the event to resolve. 
	*/ 
	void resolveEvent(sf::Event event);
	//! Sell the tower in this tile.
	/*!

	*/
	void sellTower();
	//!Draw the menu.
	/*!
	
	*/
	void draw(sf::RenderWindow&);				
	//!Close the menu.
	/*!
	
	*/
	void close();								
};