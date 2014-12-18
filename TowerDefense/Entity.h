#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Entity
{
protected:
	sf::Vector2i position;
	sf::Vector2i size;
	float speed;
	sf::Sprite sprite;
	shared_ptr<Tile> tile;
	int timer;//To define Config respectively for Enemy and Tower
	sf::Texture texture;

public:
	//! A constructor
	Entity();

	//! A virtual destructor
	virtual ~Entity();

	//! Return the current position of this entity.
	/*!
	\return A sf::Vector2i variable.
	*/
	sf::Vector2i getPosition();

	//! Return the current size of this entity.
	/*!
	\return A sf::Vector2i variable.
	*/
	sf::Vector2i getSize();

	//! Return the current speed of this entity.
	/*!
	\return A float variable.
	*/
	float getSpeed();

	//! Return current value of timer.
	/*!
	\return A integer variable.
	*/
	int getTimer();

	//! Return the current sprite of this entity.
	/*!
	\return A sf::Sprite variable.
	*/

	sf::Sprite getSprite();

	//! Return the current tile of this entity.
	/*!
	\return A shared pointer pointing a type Tile.
	*/
	shared_ptr<Tile> getTile();

	//! Set postion of this entity.
	/*!
	\param mPosition A sf::Vector2i variable
	*/
	void setPosition(sf::Vector2i mPosition);
	
	//! Set size of this entity.
	/*!
	\param mSize A sf::Vector2i variable
	*/
	void setSize(sf::Vector2i mSize);

	//! Set speed of this entity.
	/*!
	\param mSpeed A float variable
	*/
	void setSpeed(float mSpeed);

	//! Set timer of this entity.
	/*!
	\param mTimer A integer variable.
	*/
	void setTimer(int mTimer);

	//! Set sprite of this entity.
	/*!
	\param mSprite A sf::Sprite variable
	*/
	void setSprite(sf::Sprite mSprite);

	//! To draw this entity in a render window.
	/*!
	\param w A sf::RenderWindow reference variable.
	*/
	virtual void draw(sf::RenderWindow& w);
};

