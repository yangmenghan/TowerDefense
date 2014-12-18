#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Menu.h"
#include "AudioManager.h"
#include "LevelManager.h"
#include "Button.h"
#include "Config.h"
#include "MenuManager.h"

class GameMenu 
	: public Menu
{
private:
	Button pauseButton = Button(PAUSE_BUTTON_TEXTURE, MUTE_BUTTON_SIZE, MUTE_BUTTON_POSITION + sf::Vector2i(120,0), 2);
	Button speedButton = Button(SPEED_BUTTON_TEXTURE, MUTE_BUTTON_SIZE, MUTE_BUTTON_POSITION + sf::Vector2i(240, 0), 2);
	Button muteButton = Button(MUTE_BUTTON_TEXTURE, MUTE_BUTTON_SIZE, MUTE_BUTTON_POSITION, 2);
	Button restartButton = Button(RESTART_BUTTON_TEXTURE, BACK_BUTTON_SIZE, RESTART_BUTTON_POSITION, 3);
	Button giveUpButton = Button(GIVE_UP_BUTTON_TEXTURE, BACK_BUTTON_SIZE, RESTART_BUTTON_POSITION + sf::Vector2i(120, 0), 3);
	float gameSpeed;

	LevelManager* levelManager;

	std::string fontAddress;
	sf::Font font;
	sf::Text lifeCountDisplay; //is it the best way to proceed ? will need tests
	sf::Text pointsCountDisplay;
	sf::Text waveCountDisplay;
	sf::Text moneyCountDisplay;
	sf::Text comingWaveDisplay;


public:

//! Default Constructor
	GameMenu();

//! Constructor inherited from mother class Menu
	GameMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition);

//! Destructor
	~GameMenu();

//! Gets game speed
	/*!
		\return float
	*/
	float getGameSpeed();

//! Sets game speed
	/*!
		\param float speed value to which game speed will be set
	*/
	void setGameSpeed(float);


//Fonctions

//! Pause Game
	/*!
		Pauses game
	*/
	void pauseGame();

//! Speed Game up
	/*!
		Speeds game up if the game is paused or at normal speed
	*/
	void speedGame();

//! Return speed
	/*!
		Resets speed of the game
	*/
	void returnSpeed();

//! Restart game
	/*!
	Resets game
	*/
	void restartGame();

//! Draw
	/*!
		Displays elements of the game, such as buttons and player values
	*/
	void draw(sf::RenderWindow& w);

//! Resolve event
	/*!
		Handles events in the game. Passes them to buttons and game fields.
	*/
	void resolveEvent(sf::Event event);


//! Display coming wave number
	/*!
	displays the number of the coming way
	*/
	void displayComingWay();
};