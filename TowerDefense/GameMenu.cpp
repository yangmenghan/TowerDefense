#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"
#include <string>

GameMenu::GameMenu()
{

}

GameMenu::GameMenu(std::string myTextureAdress, sf::Vector2u mySize, sf::Vector2i myPosition)
{
	Menu(myTextureAdress, mySize, myPosition);
}

GameMenu::~GameMenu(){}

//Getters
sf::Text GameMenu::getLifeCountDisplay()
{
	return lifeCountDisplay;
}

sf::Text GameMenu::getPointsCountDisplay()
{
	return pointsCountDisplay;
}

sf::Text GameMenu::getWaveCountDisplay()
{
	return waveCountDisplay;
}

//Setters

void GameMenu::setLifeCountDisplay(int myLifeCount)
{
	lifeCountDisplay.setString(to_string(myLifeCount));
}

void GameMenu::setPointsCountDisplay(int myPointsCount)
{
	pointsCountDisplay.setString(to_string(myPointsCount));
}

void GameMenu::setWaveCountDisplay(int myWaveCount)
{
	waveCountDisplay.setString(to_string(myWaveCount));
}

//Functions

void GameMenu::pauseGame()
{
	LevelManager levelManager = LevelManager::getLevelManager();
	levelManager.setSpeed(0);
}

void GameMenu::returnSpeed()
{
	LevelManager levelManager = LevelManager::getLevelManager();
	levelManager.setSpeed(1);
}

void GameMenu::speedGame()
{
	LevelManager levelManager = LevelManager::getLevelManager();
	levelManager.setSpeed(2);
}


void GameMenu::restartGame()
{
	GameMenu newGame = GameMenu::GameMenu();

	MenuManager* m = MenuManager::getMenuManager();

	m->popMenu();
	m->addMenu(newGame);

	this -> ~GameMenu();
}

void GameMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
	pauseButton.draw(w);
	speedButton.draw(w);
	muteButton.draw(w);
	restartButton.draw(w);
	giveUpButton.draw(w);

	//set position and font for the text displays

	w.draw(lifeCountDisplay);
	w.draw(pointsCountDisplay);
	w.draw(waveCountDisplay);

}

void GameMenu::resolveEvent(sf::Event event)
{
	if (pauseButton.mouseClick(event))
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
	}
}


