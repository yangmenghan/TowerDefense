#pragma once
#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Button.h"
#include "Config.h"


// needs creation of Button class

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
	int waveCount;
	int waveTotal;

	sf::Text lifeCountDisplay;
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
	int getWaveCount();
	int getWaveTotal();

//Setters
	void setGameSpeed(float);
	void setWaveCount(int);
	void setWaveTotal(int); // not useful ?

	

//Fonctions
	void pauseGame();
	void speedGame();
	void returnSpeed();
	void restartGame();
	void startWave();
	void display();
};