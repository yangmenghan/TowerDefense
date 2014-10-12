#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"

GameMenu::GameMenu()
{
	size.x = GAME_MENU_WIDTH;
	size.y = GAME_MENU_HEIGHT;
	gameSpeed = 1;
	waveTotal = WAVE_TOTAL;
	waveCount = 0;

	sf::Texture t;
	if (!t.loadFromFile(GAME_MENU_DEFAULT_TEXTURE))
	{
		// TODO erreur...
	}

	texture = t;
}

GameMenu::GameMenu(sf::Texture t, float w, float h, int n)
{
	size.x = w;
	size.y = h;
	texture = t;
	gameSpeed = 1;
	waveTotal = n;
	waveCount = 0;
}

GameMenu::~GameMenu(){}

float GameMenu::getGameSpeed()
{
	return gameSpeed;
}

int GameMenu::getWaveCount()
{
	return waveCount;
}

int GameMenu::getWaveTotal()
{
	return waveTotal;
}

void GameMenu::setGameSpeed(float gs)
{
	gameSpeed = gs;
}

void GameMenu::setWaveCount(int wc)
{
	waveCount = wc;
}

void GameMenu::setWaveTotal(int wt)
{
	waveTotal = wt;
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

void GameMenu::startWave()
{

}



