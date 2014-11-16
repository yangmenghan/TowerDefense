#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Menu.h"
#include "Button.h"
#include "Config.h"

class GameMenu 
	: public Menu
{
private:
	Button pauseButton = Button(PAUSE_BUTTON_TEXTURE);
	Button speedButton = Button(SPEED_BUTTON_TEXTURE);
	Button muteButton = Button(MUTE_BUTTON_TEXTURE);
	Button restartButton = Button(RESTART_BUTTON_TEXTURE);
	Button giveUpButton = Button(GIVE_UP_BUTTON_TEXTURE);

	enum Actions {Pause, SpeedUp, ReturnSpeed, Mute, RestartGame, Exit};

	float gameSpeed;

	sf::Text lifeCountDisplay; //is it the best way to proceed ? will need tests
	sf::Text pointsCountDisplay;
	sf::Text waveCountDisplay;

public:
//Constructors, destructors
	GameMenu();
	GameMenu(sf::Texture, sf::Vector2f, int);
	~GameMenu();

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
	void resolveEvent();
};