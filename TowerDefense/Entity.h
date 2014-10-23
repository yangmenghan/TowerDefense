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
	void setPosition(sf::Vector2f mPosition);
	void setSize(sf::Vector2f mSize);
	void setSpeed(float mSpeed);
	void setSprite(sf::Sprite mSprite);

	//Functions
	Tile getTile();
	void resolveCollision(Entity mEntity);
	void draw(sf::RenderWindow&);
};

