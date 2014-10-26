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
	while (w.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			w.close();
			break;

			// mouse
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				
			}

			// we don't process other types of events
		default:
			break;
		}
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

