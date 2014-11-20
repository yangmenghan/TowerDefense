#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"

GameMenu::GameMenu()
{
}

GameMenu::GameMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition)
{
	Menu(myTextureAddress, mySize, myPosition);
	gameSpeed = 1;
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
	/*pauseButton.draw(w);
	speedButton.draw(w);
	muteButton.draw(w);
	restartButton.draw(w);
	giveUpButton.draw(w);*/

	//set position and font for the text displays

	w.draw(lifeCountDisplay);
	w.draw(pointsCountDisplay);
	w.draw(waveCountDisplay);
}

void GameMenu::resolveEvent()
{
	/*if (pauseButton.mouseClick(event))
	{
		int gameSpeed = LevelManager::getLevelManager().getSpeed();
		if (gameSpeed == 0)
		{
			returnSpeed();
		}
		else
		{
			pauseGame();
		}
		
	}
	if (speedButton.mouseClick(event))
	{
		int gameSpeed = LevelManager::getLevelManager().getSpeed();
		if (gameSpeed == 2)
		{
			returnSpeed();
		}
		else
		{
			speedGame();
		}
	}
	if (muteButton.mouseClick(event))
	{
		AudioManager audio = AudioManager::getAudioManager();
		if (audio.isMute() == false)
		{
			muteGame();
		}
		else
		{
			playMusic();
		}
	}
	if (restartButton.mouseClick(event))
	{
		restartGame();
	}
	if (giveUpButton.mouseClick(event))
	{
		//game over
	}*/
}


