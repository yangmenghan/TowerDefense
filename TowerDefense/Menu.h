#pragma once
#include <SFML\Graphics.hpp>
#include <string>

class Menu
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	std::string textureAddress;
	sf::Vector2f size;
	sf::Vector2f position;

public:
//Constructor and destructor
	Menu();
	~Menu();

//Setters
	void setSize(sf::Vector2f);
	void setPosition(sf::Vector2f);
	void setAddress(std::string);
	void setTexture(sf::Texture);
	void setTexture(std::string);
	void setSprite(sf::Sprite);
	void setSprite(sf::Texture);
	void setSprite(std::string);



//Getters
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	sf::Sprite getSprite();
	sf::Texture getTexture();
	std::string getAddress();


//Functions
	void display();
	void close();
};