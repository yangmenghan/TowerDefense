#pragma once

#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "CreditsMenu.h"
#include "Button.h"
#include "Config.h"
#include "AudioManager.h"
#include <vector>
#include <string>

class StartMenu : public Menu
{
private:
	
	Button startGameButton = Button(START_GAME_BUTTON_TEXTURE, BUTTON_SIZE, START_BUTTON_POSITION, 3);
	Button openCreditsButton = Button(CREDITS_BUTTON_TEXTURE, BUTTON_SIZE, CREDITS_BUTTON_POSITION,3);
	Button muteButton = Button(MUTE_BUTTON_TEXTURE, MUTE_BUTTON_SIZE, MUTE_BUTTON_POSITION,2);
	Button tutorialButton = Button(TUTORIAL_BUTTON_TEXTURE, BUTTON_SIZE, TUTORIAL_BUTTON_POSITION, 3);
	Button exitGameButton = Button(EXIT_GAME_BUTTON_TEXTURE, BUTTON_SIZE, EXIT_BUTTON_POSITION,3);

public:

//! Default Constructor
	StartMenu();

//! Constructor inherited from Menu class
	StartMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition);
	
//! Destructor
	~StartMenu();

//! Draw
	/*!
		Displays background and buttons
	*/
	void draw(sf::RenderWindow&);

//! Resolve Event
	/*!
		Handles all events in the menu and handles them to buttons
	*/
	void resolveEvent(sf::Event); 

//! Start Game
	/*!
		Lauches game when start game button is clicked
	*/
	void startGame();

//! Open Credits
	/*!
		Opens Credits menu when associated button is clicked
	*/
	void openCredits();

//! Open Tutorial
	/*!
	Opens how to play when associated button is clicked
	*/
	void openTutorial();

//! Exit Game
	/*!
		Exits the game
	*/
	void exitGame();
};