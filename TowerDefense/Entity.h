#pragma once
#include<SFML/Graphics.hpp>

class Entity
{
protected:
	sf::Vector2f position;
	sf::Vector2f size;
	float speed;
	sf::Sprite sprite;

public:
	Entity();
	~Entity();

	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	float getSpeed();
	sf::Sprite getSprite();

	void setPosition(sf::Vector2f _position);
	void setSize(sf::Vector2f _size);
	void setSpeed(float _speed);
	void setSprite(sf::Sprite _sprite);

	Tile getTile();//After the creation of class Tile
	void resolveCollision(Entity _entity);
	void draw();
};

