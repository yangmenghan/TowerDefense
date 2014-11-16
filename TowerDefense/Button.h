#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Config.h"

class Button
{
private:
	std::string textureAddress;
	sf::Texture spriteSheet;
	sf::Sprite sprite;
	sf::Vector2i position;
	sf::Vector2i size;

	int currentSprite;
	int totalSprites;

	sf::FloatRect boundingBox;

public:
//Constructors and destroyers
	Button();
	Button(std::string myTextureAddress, sf::Vector2i mySize, sf::Vector2i myPosition, int n);
	~Button();

//Getters
	sf::Vector2i getPosition();
	sf::Vector2i getSize();
	sf::Sprite getSprite();

//Setters
	void setPosition(sf::Vector2i mPosition);
	void setSize(sf::Vector2i mSize);
	void setSprite(sf::Sprite mSprite);

//Functions
	void draw(sf::RenderWindow&); 
	bool mouseHover();
	bool mouseClicking(sf::Event);
	bool mouseClick(sf::Event);
	void spriteUpdate();

};