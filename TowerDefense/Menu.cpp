#include "Menu.h"

Menu::Menu(sf::Vector2f mySize, sf::Vector2f myPosition, sf::Texture myTexture)
{
	size = mySize;
	position = myPosition;
	texture = myTexture;
}

sf::Vector2f Menu::getSize()
{
	return size;
}

sf::Vector2f Menu::getPosition()
{
	return position;
}
sf::Texture Menu::getTexture()
{
	return texture;
}

void Menu::setSize(sf::Vector2f mySize)
{
	size = mySize;
}

void Menu::setPosition(sf::Vector2f myPosition)
{
	position = myPosition;
}

void Menu::setTexture(sf::Texture myTexture)
{
	texture = myTexture;
}

//TO DO

void Menu::draw()
{

}

void Menu::close()
{

}