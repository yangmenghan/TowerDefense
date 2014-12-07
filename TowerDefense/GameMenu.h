#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Menu.h"
#include "AudioManager.h"
#include "LevelManager.h"
#include "Button.h"
#include "Config.h"
#include "LevelManager.h"

class GameMenu 
	: public Menu
{
private:
	Button pauseButton = Button(PAUSE_BUTTON_TEXTURE, MUTE_BUTTON_SIZE, MUTE_BUTTON_POSITION + sf::Vector2i(120,0), 2);
	Button speedButton = Button(SPEED_BUTTON_TEXTURE, MUTE_BUTTON_SIZE, MUTE_BUTTON_POSITION + sf::Vector2i(240, 0), 2);
	Button muteButton = Button(MUTE_BUTTON_TEXTURE, MUTE_BUTTON_SIZE, MUTE_BUTTON_POSITION, 2);
	Button restartButton = Button(RESTART_BUTTON_TEXTURE, MUTE_BUTTON_SIZE, MUTE_BUTTON_POSITION + sf::Vector2i(360, 0), 2);
	//Button giveUpButton = Button(GIVE_UP_BUTTON_TEXTURE);
	float gameSpeed;

	LevelManager* levelManager;

	sf::Text lifeCountDisplay; //is it the best way to proceed ? will need tests
	sf::Text pointsCountDisplay;
	sf::Text waveCountDisplay;


public:

//Constructors, destructors
	GameMenu();
	GameMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition);
	~GameMenu();
	
	void opent(){}; //TODO : for test

//Getters
//Do we need getters and setters for buttons ?
	float getGameSpeed();

//Setters
	void setGameSpeed(float);


//Fonctions
	void pauseGame();
	void speedGame();
	void returnSpeed();
	void restartGame();
	void draw(sf::RenderWindow& w);
	void resolveEvent(sf::Event event);
};