#include "GameOverMenu.h"

//Constructor and destroyers
GameOverMenu::GameOverMenu(sf::RenderWindow& w)
{
	size = w.getSize();
	textureAddress = GAMEOVER_MENU_TEXTURE;
	if (!texture.loadFromFile(textureAddress))
	{
		//error
	}
	sprite.setTexture(texture);
	//position??
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
	m->addMenu(gameMenu);
}

void GameOverMenu::exitGame()
{
	MenuManager* m = MenuManager::getMenuManager();
	m->~MenuManager();
}