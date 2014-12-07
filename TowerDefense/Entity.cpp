#include "Entity.h"


Entity::Entity()
{
}


Entity::~Entity()
{
}

/*
Getters and Setters
*/
sf::Vector2i Entity::getPosition()
{
	return position;
}

sf::Vector2i Entity::getSize()
{
	return size;
}

float Entity::getSpeed()
{
	return speed;
}

sf::Sprite Entity::getSprite()
{
	return sprite;
}

shared_ptr<Tile> Entity::getTile()
{
	return tile;
}

void Entity::setPosition(sf::Vector2i mPosition)
{
	position = mPosition;
}

void Entity::setSize(sf::Vector2i mSize)
{
	size = mSize;
}

void Entity::setSpeed(float mSpeed)
{
	speed = mSpeed;
}

void Entity::setSprite(sf::Sprite mSprite)
{
	sprite = mSprite;
}


/*
Draw the entity in a Render Window
*/

void Entity::draw(sf::RenderWindow &w)
{
	w.draw(sprite);
}