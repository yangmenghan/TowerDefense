#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f size;

public:
//Constructors and destroyers
	Button();
	~Button();

//Getters
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	sf::Sprite getSprite();

//Setters
	void setPosition(sf::Vector2f mPosition);
	void setSize(sf::Vector2f mSize);
	void setSprite(sf::Sprite mSprite);

//Functions
	void draw();
	void mouseClick();
	void mouseHover();

};