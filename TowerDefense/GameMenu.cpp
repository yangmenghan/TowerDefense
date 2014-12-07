#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"
#include "LevelManager.h"

GameMenu::GameMenu()
{
	levelManager = LevelManager::getLevelManager();
}

GameMenu::GameMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition) : Menu(myTextureAddress, mySize, myPosition)
{
	gameSpeed = 1;
	levelManager = LevelManager::getLevelManager();
}

GameMenu::~GameMenu(){}

//Getters

float GameMenu::getGameSpeed()
{
	return gameSpeed;
}


//Setters

void GameMenu::setGameSpeed(float myGameSpeed)
{
	gameSpeed = myGameSpeed;
}


//Functions

void GameMenu::pauseGame()
{
	gameSpeed = 0;
}

void GameMenu::returnSpeed()
{
	gameSpeed = 1;
}

void GameMenu::speedGame()
{
	gameSpeed = 2;
}

	//TO DO

void GameMenu::restartGame()
{

}


void GameMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);

	pauseButton.mouseHover(w);
	speedButton.mouseHover(w);
	muteButton.mouseHover(w);
	restartButton.mouseHover(w);
	//giveUpButton.draw(w);
	
	pauseButton.draw(w);
	speedButton.draw(w);
	muteButton.draw(w);
	restartButton.draw(w);
	//giveUpButton.draw(w);

	
	//set position and font for the text displays

	w.draw(lifeCountDisplay);
	w.draw(pointsCountDisplay);
	w.draw(waveCountDisplay);

	levelManager->gameLoop(w);
}

void GameMenu::resolveEvent(sf::Event event)
{
	
	if (pauseButton.checkHover())
	{
		pauseButton.resolveEvent(event);
		if (pauseButton.checkClick())
		{
			if (gameSpeed == 0)
			{
				returnSpeed();
			}
			else
			{
				pauseGame();
			}
		}
	}
	if (speedButton.checkHover())
	{
		speedButton.resolveEvent(event);
		if (speedButton.checkClick())
		{
			if (gameSpeed == 2)
			{
				returnSpeed();
			}
			else
			{
				speedGame();
			}
		}
	}
	if (muteButton.checkHover())
	{
		muteButton.resolveEvent(event);
		if (muteButton.checkClick())
		{
			AudioManager audio = AudioManager::getAudioManager();
			if (audio.isMute() == false)
			{
				audio.mute();
			}
			else
			{
				audio.play();
			}
		}
	}
	if (restartButton.checkHover())
	{
		restartButton.resolveEvent(event);
		if (restartButton.checkClick())
		{
			restartGame();
		}
	}
	//LevelManager::getLevelManager()->getField().resolveEvent(event,w);

	/*
	if (giveUpButton.mouseClick(event))
	{
		//game over
	}*/
}


