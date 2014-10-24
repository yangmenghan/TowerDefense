#include "Menu.h"

//Getters

sf::Vector2u Menu::getSize()
{
	return size;
}

sf::Vector2i Menu::getPosition()
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

//Setters

void Menu::setSize(sf::Vector2u mySize)
{
	size = mySize;
}

void Menu::setPosition(sf::Vector2i myPosition)
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

//Functions

void Menu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
}

void Menu::close()
{}

void Menu::resolveEvent()
{}