#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"

GameMenu::GameMenu()
{
	size.x = GAME_MENU_WIDTH;
	size.y = GAME_MENU_HEIGHT;
	gameSpeed = 1;

	sf::Texture t;
	if (!t.loadFromFile(GAME_MENU_DEFAULT_TEXTURE))
	{
		// TODO erreur...
	}

	texture = t;
	sprite.setTexture(texture);
}

GameMenu::GameMenu(sf::Texture myTexture, sf::Vector2f mySize, int myWaveTotal)
{
	size = mySize;
	texture = myTexture;
	gameSpeed = 1;

	sprite.setTexture(texture);
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
	pauseButton.draw(w);
	speedButton.draw(w);
	muteButton.draw(w);
	restartButton.draw(w);
	giveUpButton.draw(w);
}

void GameMenu::resolveEvent()
{

}


