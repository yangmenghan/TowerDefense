#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "MenuManager.h"

class Menu
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	std::string textureAddress;
	sf::Vector2u size;
	sf::Vector2i position;

public:
//Constructor and destructor
	Menu();
	Menu(std::string myTextureAdress, sf::Vector2u mySize, sf::Vector2i myPosition);
	~Menu(); 

//Setters
	void setSize(sf::Vector2u);
	void setPosition(sf::Vector2i);

	void setAddress(std::string);

	void setTexture(sf::Texture);
	void setTexture(std::string);

	void setSprite(sf::Sprite);
	void setSprite(sf::Texture);
	void setSprite(std::string);



//Getters
	sf::Vector2u getSize();
	sf::Vector2i getPosition();
	sf::Sprite getSprite();
	sf::Texture getTexture();
	std::string getAddress();


//Functions
	void draw(sf::RenderWindow&);
	void close();
	void opent();
	void resolveEvent(sf::Event);
};