#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Menu.h"
#include "MenuManager.h"
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
	
	if (!font.loadFromFile(FONT))
	{
		//error
	}

	lifeCountDisplay.setFont(font);
	pointsCountDisplay.setFont(font);
	waveCountDisplay.setFont(font);

	lifeCountDisplay.setColor(sf::Color::Green);
	pointsCountDisplay.setColor(sf::Color::Green);
	waveCountDisplay.setColor(sf::Color::Green);

	lifeCountDisplay.setCharacterSize(14);
	pointsCountDisplay.setCharacterSize(14);
	waveCountDisplay.setCharacterSize(14);

	lifeCountDisplay.setPosition(LIFE_COUNT_DISPLAY_POSITION);
	pointsCountDisplay.setPosition(POINTS_COUNT_DISPLAY_POSITION);
	waveCountDisplay.setPosition(WAVE_COUNT_DISPLAY_POSITION);

	shared_ptr<AudioManager> audio = AudioManager::getAudioManager();
	if (audio->isMute() == false)
	{
		muteButton.spriteUpdate(0);
	}
	else
	{
		muteButton.spriteUpdate(1);
	}
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
	LevelManager::getLevelManager()->setSpeed(0);
}

void GameMenu::returnSpeed()
{
	gameSpeed = 1;
	LevelManager::getLevelManager()->setSpeed(1);
}

void GameMenu::speedGame()
{
	gameSpeed = 2;
	LevelManager::getLevelManager()->setSpeed(2);
}

	//TO DO

void GameMenu::restartGame()
{
	//MenuManager* m = MenuManager::getMenuManager();

	//m->popMenu();
	//m->addMenu(make_shared<GameMenu>(GAME_MENU_DEFAULT_TEXTURE, sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT), sf::Vector2i(0, 0)));

	LevelManager::getLevelManager()->restartGame();

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

	std::string lifeCount = std::to_string(levelManager->getPlayer()->getHP());
	lifeCountDisplay.setString("Player life : " + lifeCount+"/10");

	std::string pointsCount = std::to_string(levelManager->getPlayer()->getScore());
	pointsCountDisplay.setString("Player score : " + pointsCount);

	string waveCount = std::to_string((levelManager->getCurrentWaveNumber()));
	waveCountDisplay.setString("Wave " + waveCount + "/24");

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
			shared_ptr<AudioManager> audio = AudioManager::getAudioManager();
			if (audio->isMute() == false)
			{
				audio->mute();
			}
			else
			{
				audio->play();
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
	LevelManager::getLevelManager()->getField().resolveEvent(event);

	/*
	if (giveUpButton.mouseClick(event))
	{
		//game over
	}*/
}


