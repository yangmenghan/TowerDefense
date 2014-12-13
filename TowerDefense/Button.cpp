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
	box = sf::IntRect(position, size);

	isClicking = false;
	isHovered = false;
	isClicked = false;

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

bool Button::checkClick()
{
	return isClicked;
}

bool Button::checkHover()
{
	return isHovered;
}

void Button::setClickedState(bool mIsClicked)
{
	isClicked = mIsClicked;
}

void Button::setPosition(sf::Vector2i mPosition)
{
	position = mPosition;
}

void Button::setSize(sf::Vector2i mSize)
{
	size = mSize;
}

void Button::draw(sf::RenderWindow& w)
{
	sprite.setTexture(spriteSheet);

	sf::Vector2i spriteInit(0, currentSprite*(size.y));
	sprite.setTextureRect(sf::IntRect(spriteInit, size));

	sprite.setPosition(sf::Vector2f(float(position.x), float(position.y)));
	w.draw(sprite);
}

void Button::resolveEvent(sf::Event event)
{
	if (totalSprites == 3)
	{
		spriteUpdate(1);
	}
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (totalSprites == 3)
		{
			spriteUpdate(2);
		}
		isClicking = true;
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (isClicking == true)
		{
			if (totalSprites == 3)
			{
				spriteUpdate(0);
			}
			else if (totalSprites == 2)
			{
				if (currentSprite == 0)
				{
					spriteUpdate(1);
				}
				else
				{
					spriteUpdate(0);
				}
			}
			isClicked = true;
			isClicking = false;
		}
	}
	else
	{
		isClicked = false;
	}
}

void Button::spriteUpdate(int i)
{
	currentSprite = i;
}

bool Button::mouseHover(sf::RenderWindow& w)
{
	if (box.contains(sf::Mouse::getPosition(w)))
	{
		isHovered = true;
	}
	else
	{
		if (totalSprites == 3)
		{
			spriteUpdate(0);
		}
		isHovered = false;
	}
	return isHovered;
}