#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Menu.h"
#include "MenuManager.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"
#include "LevelManager.h"
#include "GameOverMenu.h"

GameMenu::GameMenu()
{
	levelManager = LevelManager::getLevelManager();
	levelManager->startGame();
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
	moneyCountDisplay.setFont(font);
	comingWaveDisplay.setFont(font);

	lifeCountDisplay.setColor(sf::Color::Green);
	pointsCountDisplay.setColor(sf::Color::Green);
	waveCountDisplay.setColor(sf::Color::Green);
	moneyCountDisplay.setColor(sf::Color::Green);
	comingWaveDisplay.setColor(sf::Color::Green);

	lifeCountDisplay.setCharacterSize(14);
	pointsCountDisplay.setCharacterSize(14);
	waveCountDisplay.setCharacterSize(14);
	moneyCountDisplay.setCharacterSize(14);
	comingWaveDisplay.setCharacterSize(50);

	lifeCountDisplay.setPosition(LIFE_COUNT_DISPLAY_POSITION);
	pointsCountDisplay.setPosition(POINTS_COUNT_DISPLAY_POSITION);
	waveCountDisplay.setPosition(WAVE_COUNT_DISPLAY_POSITION);
	moneyCountDisplay.setPosition(MONEY_COUNT_DISPLAY_POSITION);
	comingWaveDisplay.setPosition(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 100);

	shared_ptr<AudioManager> audio = AudioManager::getAudioManager();
	if (audio->isMute() == false)
	{
		muteButton.spriteUpdate(0);
	}
	else
	{
		muteButton.spriteUpdate(1);
	}

	levelManager->startGame();
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
	LevelManager::getLevelManager()->restartGame();
}


void GameMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
	levelManager->display(w);

	pauseButton.mouseHover(w);
	speedButton.mouseHover(w);
	muteButton.mouseHover(w);
	restartButton.mouseHover(w);
	giveUpButton.mouseHover(w);
	
	pauseButton.draw(w);
	speedButton.draw(w);
	muteButton.draw(w);
	restartButton.draw(w);
	giveUpButton.draw(w);

	
	//set position and font for the text displays

	std::string lifeCount = std::to_string(levelManager->getPlayer()->getHP());
	lifeCountDisplay.setString("Player life : " + lifeCount+"/10");

	std::string pointsCount = std::to_string(levelManager->getPlayer()->getScore());
	pointsCountDisplay.setString("Score : " + pointsCount);

	std::string moneyCount = std::to_string(levelManager->getPlayer()->getMoney());
	moneyCountDisplay.setString("Gold : " + moneyCount);
	
	string waveCount = std::to_string((levelManager->getCurrentWaveNumber()));
	waveCountDisplay.setString("Wave " + waveCount + "/" + std::to_string(WAVE_TOTAL));

	w.draw(lifeCountDisplay);
	w.draw(pointsCountDisplay);
	w.draw(waveCountDisplay);
	w.draw(moneyCountDisplay);
	w.draw(comingWaveDisplay);

	if (levelManager->getTrigger())
	{
		if ((levelManager->getCurrentWaveNumber() + 1) == WAVE_TOTAL)
		{
			comingWaveDisplay.setString("Last Wave");
		}
		else if ((levelManager->getCurrentWaveNumber() + 1) == WAVE_TOTAL + 1)
		{
			comingWaveDisplay.setString("Finished");
		}
		else
		{
			comingWaveDisplay.setString("Wave " + std::to_string((levelManager->getCurrentWaveNumber() + 1)) + "!");
		}
	}
	else
	{
		comingWaveDisplay.setString("");
	}
	
	levelManager->gameLoop(w);

}

void GameMenu::resolveEvent(sf::Event event)
{
	if (pauseButton.checkHover())
	{
		pauseButton.resolveEvent(event);
		if (pauseButton.checkClick())
		{
			speedButton.spriteUpdate(0);
			if (gameSpeed != 0)
			{
				pauseGame();
			}
			else
			{
				returnSpeed();
			}
		}
	}
	if (speedButton.checkHover())
	{
		speedButton.resolveEvent(event);
		if (speedButton.checkClick())
		{
			pauseButton.spriteUpdate(0);
			if (gameSpeed != 2)
			{
				speedGame();
			}
			else
			{
				returnSpeed();
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

	if (giveUpButton.checkHover())
	{
		giveUpButton.resolveEvent(event);
		if (giveUpButton.checkClick())
		{
			levelManager->gameOver();
		}
	}
	
	LevelManager::getLevelManager()->getField().resolveEvent(event);
}





