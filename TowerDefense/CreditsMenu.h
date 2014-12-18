#pragma once

#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Button.h"
#include "Config.h"
#include <string>

class CreditsMenu : public Menu
{
private:
	Button backButton = Button(BACK_BUTTON_TEXTURE, BACK_BUTTON_SIZE, RESTART_BUTTON_POSITION, 3);

public:

//! Default constructor
	CreditsMenu();

//! Constructor inherited from Menu class
	CreditsMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition);

//! Destructor
	~CreditsMenu();

//! Draw
	/*!
		Displays the menu and its buttons
	*/
	void draw(sf::RenderWindow& w);

//! Resolve Event
	/*!
		Handles all events in the menu and passes them to the buttons
	*/
	void resolveEvent(sf::Event event);

	void closeMenu();
};