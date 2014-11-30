#include "Button.h"

Button::Button()
{
}

Button::Button(const std::string myTextureAddress, sf::Vector2i mySize, sf::Vector2i myPosition, int n)
{
	textureAddress = myTextureAddress;
	size = mySize;
	position = myPosition;
	totalSprites = n;
	currentSprite = 0;

	if (!spriteSheet.loadFromFile(textureAddress))
	{
		// TODO erreur...
	}
}

Button::~Button(){};

sf::Vector2i Button::getPosition()
{
	return position;
}

sf::Vector2i Button::getSize()
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

void Button::setSize(sf::Vector2i mSize)
{
	size = mSize;
}

void Button::setSprite(sf::Sprite mSprite)
{
	sprite = mSprite;
}

void Button::draw(sf::RenderWindow& w)
{
	sprite.setTexture(spriteSheet);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), size));
	sprite.setPosition(sf::Vector2f(200, 200));
	boundingBox = sprite.getGlobalBounds();
	w.draw(sprite);
}

bool Button::mouseHover()
{
	bool isHovering = false;
	sf::Vector2f mousePosition((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y);

	if (boundingBox.contains(mousePosition))
	{
		isHovering = true;
		spriteUpdate();
	}
	else
	{
		isHovering = false;
		sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
		spriteUpdate();
	}

	return isHovering;
}

bool Button::mouseClicking(sf::Event event)
{
	if (mouseHover())
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			return true;
			spriteUpdate();
		}
	}
	return false;
}

bool Button::mouseClick(sf::Event event)
{
	if (mouseClicking(event))
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			return true;
			spriteUpdate();
		}
	}
	return false;
}

void Button::spriteUpdate()
{
	if (currentSprite != (totalSprites - 1))
	{
		currentSprite++;
	}
	else
	{
		currentSprite = 0;
	}

	sf::Vector2i spriteInit(0, currentSprite*size.y);

	sprite.setTextureRect(sf::IntRect(spriteInit, size));

}
