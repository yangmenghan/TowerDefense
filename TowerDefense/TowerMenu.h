#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <string>
#include "Button.h"
#include "Menu.h"

using namespace std;

class Tile;
//! A menu to sell or upgrade a tower.
/*!
Appeared when click on a tile which has a tower.
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
	//! Construct the tower menu with a tile. 
	/*!
	\param tile : the tile where opens the tower menu.
	*/											
	TowerMenu(shared_ptr<Tile> tile);
	//! Destructor
	/*!
	Destructor.
	*/
	~TowerMenu();								
	//! Get the tile which opens the towermenu.
	/*!
	\return Return the shared pointer of the tile.
	*/
	shared_ptr<Tile> getTile();					
	//! Resolve all the events on this tile.
	/*!
	Sell or upgrade the tower when click on the button or close the menu when click outside.
	\param event : the event to resolve. 
	*/ 
	void resolveEvent(sf::Event event);
	//! Sell the tower in this tile.
	/*!
	*/
	void sellTower();
	//!Draw the tower menu.
	/*!
	Draw the menu and show the money to upgrade or the income to sell the tower.
	*/
	void draw(sf::RenderWindow&);				
	//!Close the menu.
	/*!
	*/
	void close();								
};