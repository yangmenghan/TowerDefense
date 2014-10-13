#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2i position;
	sf::Vector2f size;

public:
//Constructors and destroyers
	Button();
	Button(sf::Vector2f, sf::Texture, sf::Vector2i);
	~Button();

//Getters
	sf::Vector2i getPosition();
	sf::Vector2f getSize();
	sf::Sprite getSprite();

//Setters
	void setPosition(sf::Vector2i mPosition);
	void setSize(sf::Vector2f mSize);
	void setSprite(sf::Sprite mSprite);

//Functions
	void draw();
	bool mouseClick();
	bool mouseHover();

};