#include "Menu.h"

Menu::Menu()
{
}

Menu::Menu()
{
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

void Menu::setSize(sf::Vector2f s)
{
	size = s;
}

void Menu::setPosition(sf::Vector2f p)
{
	position = p;
}

void Menu::setTexture(sf::Texture t)
{
	texture = t;
}