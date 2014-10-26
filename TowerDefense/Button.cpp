#include "Button.h"

Button::Button(sf::RenderWindow& myW) : w(myW)
{
	size = sf::Vector2f(0, 0);
	boundingBox = sprite.getGlobalBounds();
	position = sf::Vector2i(0, 0);
}

Button::Button(sf::RenderWindow& myW, std::string textureAddress) : w(myW)
{
	size = sf::Vector2f(0, 0);
	position = sf::Vector2i(0, 0);

	sf::Texture texture;
	if (!texture.loadFromFile(textureAddress))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
	boundingBox = sprite.getGlobalBounds();
}

Button::Button(sf::RenderWindow& myW, sf::Vector2f mySize, std::string textureAddress, sf::Vector2i myPosition) : w(myW)
{
	sf::Texture texture;
	if (!texture.loadFromFile(textureAddress))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
	boundingBox = sprite.getGlobalBounds();

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

void Button::draw()
{
	w.draw(sprite);
}

bool Button::mouseHover(sf::Event event)
{
	bool isHovering = false;
	sf::Vector2f mousePosition((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y);

	if (boundingBox.contains(mousePosition))
	{
		isHovering = true;
	}
	else
	{
		isHovering = false;
	}

	return isHovering;
}

bool Button::mouseClicking(sf::Event event)
{
	if (mouseHover(event))
	{
		while (w.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				return true;
			}
		}
	}
}

bool Button::mouseClick(sf::Event event)
{
	if (mouseClicking(event))
	{
		while (w.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonReleased)
			{
				return true;
			}
		}
	}
}

void Button::spriteUpdate(sf::Event event) // or no arguments ?
{
	if (mouseHover(event))
	{
		//sprite update
	}


}