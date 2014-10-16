#include "Menu.h"

sf::Vector2f Menu::getSize()
{
	return size;
}

sf::Vector2f Menu::getPosition()
{
	return position;
}

sf::Sprite Menu::getSprite()
{
	return sprite;
}

std::string Menu::getAddress()
{
	return textureAddress;
}

void Menu::setSize(sf::Vector2f mySize)
{
	size = mySize;
}

void Menu::setPosition(sf::Vector2f myPosition)
{
	position = myPosition;
}

void Menu::setSprite(sf::Sprite mySprite)
{
	sprite = mySprite;
}

void Menu::setSprite(sf::Texture myTexture)
{
	sprite.setTexture(myTexture);
}

void Menu::setSprite(std::string myFileName)
{
	sf::Texture myTexture;

	if (!myTexture.loadFromFile(myFileName)) 
	{
		//gestion d'erreur
	}
	else
	{
		sprite.setTexture(myTexture);
	}
}

void Menu::run()
{
	window.draw(sprite);
}

void Menu::close()
{

}