#include "Button.h"

Button::Button()
{

}

Button::Button(sf::Vector2f mySize, sf::Sprite mySprite, sf::Vector2f myPosition)
{
	size = mySize;
	sprite = mySprite;
	position = myPosition;
}


Button::~Button(){};
