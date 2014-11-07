#include "StartMenu.h"

StartMenu::StartMenu(sf::RenderWindow& myW)
{
	Menu(myW);

	size = w.getSize();
	textureAddress = START_MENU_TEXTURE;
	if (!texture.loadFromFile(textureAddress))
	{
		//error
	}
	sprite.setTexture(texture);
}

//functions

void StartMenu::draw()
{
	w.draw(sprite);
}

void StartMenu::resolveEvent()
{
	if (startGameButton.mouseClick())
	{

	}
}

void StartMenu::startGame()
{

}

void StartMenu::openCredits()
{

}

void StartMenu::exitGame()
{

}

