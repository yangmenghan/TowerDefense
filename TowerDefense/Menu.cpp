#include "Menu.h"
#include <string>

//Getters

Menu::Menu()
{

}

Menu::~Menu()
{

}

Menu::Menu(std::string myTextureAdress, sf::Vector2u mySize, sf::Vector2i myPosition)
{
	textureAddress = myTextureAdress;
	if (!texture.loadFromFile(textureAddress))
	{
		//error
	}
	sprite.setTexture(texture);
	size = mySize;
	position = myPosition;
}


sf::Vector2u Menu::getSize()
{
	return size;
}

sf::Vector2i Menu::getPosition()
{
	return position;
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

//Functions

void Menu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
}

void Menu::close()
{}

void Menu::resolveEvent(sf::Event event)
{}