#include "GameOverMenu.h"
#include "MenuManager.h"

//Constructor and destroyers
GameOverMenu::GameOverMenu()
{
}

GameOverMenu::GameOverMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition) : Menu(myTextureAddress, mySize, myPosition)
{
	
}

GameOverMenu::~GameOverMenu(){}

//Functions

void GameOverMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
	reStartGameButton.mouseHover(w);
	reStartGameButton.draw(w);
	exitGameButton.draw(w);
	exitGameButton.draw(w);
}

void GameOverMenu::resolveEvent(sf::Event event)
{
	if (reStartGameButton.checkHover())
	{
		reStartGameButton.resolveEvent(event);
		if (reStartGameButton.checkClick())
		{
			reStartGame();
		}
	}
	else if (exitGameButton.checkHover())
	{
		exitGameButton.resolveEvent(event);
		if (exitGameButton.checkClick())
		{
			exitGame();
		}
	}
}
	


void GameOverMenu::reStartGame()
{
	MenuManager* m = MenuManager::getMenuManager();
	LevelManager::getLevelManager()->restartGame();
	m->popMenu();
}

void GameOverMenu::exitGame()
{
	MenuManager* m = MenuManager::getMenuManager();
	LevelManager::getLevelManager()->stopGame();
	m->popMenu();
	m->popMenu();
	//m->~MenuManager();
	//TODO
}