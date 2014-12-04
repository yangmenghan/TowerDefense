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
	reStartGameButton.draw(w);
	exitGameButton.draw(w);
}

void GameOverMenu::resolveEvent(sf::Event _event)
{
	/*if (reStartGameButton.resolveEvent(_event))
	{
		reStartGame();
	}
	if (exitGameButton.resolveEvent(_event))
	{
		exitGame();
	}*/
}

void GameOverMenu::reStartGame()
{
	MenuManager* m = MenuManager::getMenuManager();
	m->popMenu();
	m->addMenu(make_shared<GameMenu>());
	this->~GameOverMenu();
}

void GameOverMenu::exitGame()
{
	MenuManager* m = MenuManager::getMenuManager();
	//m->~MenuManager();
	//TODO
}