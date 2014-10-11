#pragma once
#include<SFML/Graphics.hpp>
#include"Tile.h"

class Entity
{
protected:
	sf::Vector2f position;
	sf::Vector2f size;
	float speed;
	sf::Sprite sprite;

public:
	//Constructors and destroyers
	Entity();
	~Entity();

	//Getters
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	float getSpeed();
	sf::Sprite getSprite();

	//Setters
	void setPosition(sf::Vector2f _position);
	void setSize(sf::Vector2f _size);
	void setSpeed(float _speed);
	void setSprite(sf::Sprite _sprite);

	//Functions
	Tile getTile();
	void resolveCollision(Entity _entity);
	void draw();
};

