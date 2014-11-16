#include "GameOverMenu.h"

//Constructor and destroyers
GameOverMenu::GameOverMenu()
{
}

GameOverMenu::GameOverMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition)
{
	Menu(myTextureAddress, mySize, myPosition);
}

GameOverMenu::~GameOverMenu(){}

//Functions

void GameOverMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
	reStartGameButton.draw(w);
	exitGameButton.draw(w);
}

void GameOverMenu::resolveEvent(sf::Event _event)
{
	if (reStartGameButton.mouseClick(_event))
	{
		reStartGame();
	}
	if (exitGameButton.mouseClick(_event))
	{
		exitGame();
	}
}

void GameOverMenu::reStartGame()
{
	GameMenu gameMenu = GameMenu();
	MenuManager* m = MenuManager::getMenuManager();
	m->popMenu();
	m->addMenu(gameMenu);
	this->~GameOverMenu();
}

void GameOverMenu::exitGame()
{
	MenuManager* m = MenuManager::getMenuManager();
	m->~MenuManager();
}