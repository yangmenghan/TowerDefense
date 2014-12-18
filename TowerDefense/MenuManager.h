#pragma once

#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <vector>
#include <memory>

using namespace std;

class MenuManager
{
private:
	vector<shared_ptr<Menu>> menuStack;
	bool exitFlag;
	bool existBTMenu;

	MenuManager();
	~MenuManager();

public:

//! Menu Manager
	/*!
		A pointer to the Menu Manager singleton
	*/
	static MenuManager* menuManager;

//! Get Active Menu
	/*!
	Gets the menu on top of the menu stack
	\return shared_ptr<Menu>
	*/
	shared_ptr<Menu> getActiveMenu();

//! clearMenuStack()
	/*!
	Empties the menu stack
	*/
	void clearMenuStack();

//!	Display
	/*!
		Displays menus in the Menu Stack;
		\param RenderWindow w the window in which the menus are to be displayed
	*/
	void display(sf::RenderWindow& w);

//! Add Menu
	/*!
		Adds pointer to menu on top of the menu stack
	*/
	void addMenu(shared_ptr<Menu> menu);

//! Pop Menu
	/*!
	removes top menu from the menu stack
	*/
	void popMenu();

//! Get exit flag
	/*!
		Defines if we should exit the game (if returns true)
	*/
	bool getExitFlag();

//! Exit
	/*!
		Sets the exit flag to true
	*/
	void exit();

//! Gets Exist Build/Tower Menu
	/*!
		Returns true if there is already a build tower or a tower upgrade menu open
	*/
	bool getExistBTMenu();

//! Sets Exist Build/Tower Menu
	/*!
		Sets the value of existence of a build or tower menu to true or false
	*/
	void setExistBTMenu(bool);

//! Close Menu
	/*!
		Closes the currently opened menu
	*/
	void closeMenu();

//! Get Menu Manager
	/*!
		returns a pointer to the Menu Manager singleton
	*/
	static MenuManager* getMenuManager();

//! Get Count
	/*!
		return the size of the menu stack as an int
	*/
	int getCount();

//! Resolve event
	/*! 
		Handles events to the menu on top of the stack
	*/
	void resolveEvent(sf::Event);


};