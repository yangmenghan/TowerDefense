#include "Entity.h"


Entity::Entity()
{
}


Entity::~Entity()
{
}

sf::Vector2f Entity::getPosition()
{
	return position;
}

sf::Vector2f Entity::getSize()
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

void Entity::setPosition(sf::Vector2f mPosition)
{
	position = mPosition;
}

void Entity::setSize(sf::Vector2f mSize)
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

//TODO
Tile Entity::getTile()
{
	
}

void Entity::resolveCollision(Entity mEntity)
{

}

void Entity::draw(sf::RenderWindow &w)
{

}