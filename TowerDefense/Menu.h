#pragma once
#include <SFML\Graphics.hpp>
#include <string>

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

//! Default Constructor
	Menu();

//! Constructor 
	/*!
	\param myTextureAddress the file address of the texture as a string
	\param mySize an SFML 2D Vector of integers that defines the size of the Menu
	\param myPosition an SFML 2D Vector that sets the position of the Menu (origin = top left corner)
	*/
	Menu(std::string myTextureAdress, sf::Vector2u mySize, sf::Vector2i myPosition);
	virtual ~Menu();

//Setters

//! Set size
	/*
	sets size of the Menu
	*/
	void setSize(sf::Vector2u);

//! Set position
	/*
	sets position of the Menu
	*/
	void setPosition(sf::Vector2i);

//Getters

//! Get size
	/*
	gets size of the Menu
	*/
	sf::Vector2u getSize();

//! Get position
	/*
	gets position of the Menu
	*/
	sf::Vector2i getPosition();


//Functions

//! draw
	/*
		Displays Menu
		\param w the window in which the Menu is rendered
	*/
	virtual void draw(sf::RenderWindow& w);

//! Resolve Events
	/*
	Pure virtual function
	Handles events from the menu et transmits them to buttons.
	\param an SFML event
	*/
	virtual void resolveEvent(sf::Event) = 0;

	virtual void close();
	void opent();
};