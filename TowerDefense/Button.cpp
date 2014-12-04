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

	isClicking = false;

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

	sf::Vector2i spriteInit(0, currentSprite*(size.y));
	sprite.setTextureRect(sf::IntRect(spriteInit, size));
	boundingBox = sprite.getGlobalBounds();

	sprite.setPosition(sf::Vector2f(float(position.x), float(position.y)));
	w.draw(sprite);
}

bool Button::resolveEvent(sf::Event event)
{
	bool isClicked = false;

	if (mouseHover()== true)
	{
		currentSprite = 1;
		if (event.type == sf::Event::MouseButtonPressed)
		{
			isClicking = true;
			currentSprite = 2;
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (isClicking == true)
			{
				currentSprite = 0;
				isClicked = true;
				isClicking = false;
			}
		}
	}
	
	return isClicked;
}

bool Button::mouseHover()
{
	//sf::Vector2f mousePosition((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y);
	sf::IntRect box(position, size);
	
	if (box.contains(sf::Mouse::getPosition()))
	{
		return true;
	}
	else
	{
		return false;
	}
}