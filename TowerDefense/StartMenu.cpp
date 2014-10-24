#include "StartMenu.h"

StartMenu::StartMenu(sf::RenderWindow& w)
{
	size = w.getSize();
	textureAddress = START_MENU_TEXTURE;
	if (!texture.loadFromFile(textureAddress))
	{
		//error
	}
	sprite.setTexture(texture);
}

void StartMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
}

void StartMenu::resolveEvent()
{

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

