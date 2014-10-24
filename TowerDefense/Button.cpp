#include "Button.h"

Button::Button()
{
	size = sf::Vector2f(0, 0);
	position = sf::Vector2i(0, 0);
}

Button::Button(std::string textureAddress)
{
	size = sf::Vector2f(0, 0);
	position = sf::Vector2i(0, 0);

	sf::Texture texture;
	if (!texture.loadFromFile(textureAddress))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
}

Button::Button(sf::Vector2f mySize, std::string textureAddress, sf::Vector2i myPosition)
{
	sf::Texture texture;
	if (!texture.loadFromFile(textureAddress))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);

	position = myPosition;
	size = mySize;
}


Button::~Button(){};

sf::Vector2i Button::getPosition()
{
	return position;
}

sf::Vector2f Button::getSize()
{
	return size;
}

sf::Sprite Button::getSprite()
{
	return sprite;
}

void Button::setPosition(sf::Vector2i mPosition)
{
	position = mPosition;
}

void Button::setSize(sf::Vector2f mSize)
{
	size = mSize;
}

void Button::setSprite(sf::Sprite mSprite)
{
	sprite = mSprite;
}

void Button::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
}

bool Button::mouseHover()
{
	bool isHovering = false;
	sf::Vector2i mousePosition = sf::Mouse::getPosition(); // for now gets absolute position, might need to make it relative
	//is Vector2i. Make into Vector2f ?
	if (/*position is in button*/)
	{
		isHovering = true;
		//change sprite
	}
	else
	{
		isHovering = false;
	}

	return isHovering;

}

bool Button::mouseClick()
{
	sf::Event event;
	bool isClicked = false;
	
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			if (mouseHover())
			{
				isClicked = true;
			}
		}
			
	}
	else
	{
		isClicked = false;
	}
	return isClicked;
}
