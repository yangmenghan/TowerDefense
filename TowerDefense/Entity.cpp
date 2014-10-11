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

void Entity::setPosition(sf::Vector2f _position)
{

}

void Entity::setSize(sf::Vector2f _size)
{

}

void Entity::setSpeed(float _speed)
{

}

void Entity::setSprite(sf::Sprite _sprite)
{

}

Tile Entity::getTile()
{

}

void Entity::resolveCollision(Entity _entity)
{

}

void Entity::draw()
{

}