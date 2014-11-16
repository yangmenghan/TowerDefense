#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Menu.h"
#include "Button.h"
#include "Config.h"
#include "LevelManager.h"
#include "AudioManager.h"

class GameMenu 
	: public Menu
{
private:
	//Button pauseButton = Button(PAUSE_BUTTON_TEXTURE);
	//Button speedButton = Button(SPEED_BUTTON_TEXTURE);
	//Button muteButton = Button(MUTE_BUTTON_TEXTURE);
	//Button restartButton = Button(RESTART_BUTTON_TEXTURE);
	//Button giveUpButton = Button(GIVE_UP_BUTTON_TEXTURE);

	sf::Text lifeCountDisplay; //is it the best way to proceed ? will need tests
	sf::Text pointsCountDisplay;
	sf::Text waveCountDisplay;

public:
//Constructors, destructors
	GameMenu();
	GameMenu(std::string myTextureAdress, sf::Vector2u mySize, sf::Vector2i myPosition);
	~GameMenu();

//Getters
	sf::Text getLifeCountDisplay();
	sf::Text getPointsCountDisplay();
	sf::Text getWaveCountDisplay();

//Setters
	void setLifeCountDisplay(int myLifeCount);
	void setPointsCountDisplay(int myPointsCount);
	void setWaveCountDisplay(int myWaveCount);

//Fonctions
	void pauseGame();
	void speedGame();
	void returnSpeed();

	void muteGame();
	void playMusic();
	
	void restartGame();
	void draw(sf::RenderWindow& w);
	void resolveEvent(sf::Event event);
};