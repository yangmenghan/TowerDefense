#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button
{
private:
	sf::Sprite sprite;
	sf::Vector2i position;
	sf::Vector2f size;

	sf::FloatRect boundingBox;

public:
//Constructors and destroyers
	Button();
	Button(std::string);
	Button(sf::Vector2f, std::string, sf::Vector2i);
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
	void draw(sf::RenderWindow&); 
	bool mouseHover();
	bool mouseClicking(sf::Event);
	bool mouseClick(sf::Event);
};