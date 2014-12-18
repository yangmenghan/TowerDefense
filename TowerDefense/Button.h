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

	sf::IntRect box;

	bool isHovered;
	bool isClicking;
	bool isClicked;

public:
//! Default constructor
	Button();

//! Constructor
/*!
	\param myTextureAddress the file address of the texture as a string
	\param mySize an SFML 2D Vector of integers that will define the size of the button
	\param myPosition an SFML 2D Vector of integers that will set the position of the button (origin = top left corner)
	\param n an integer which describes the number of sprites in the texture
*/
	Button(const std::string myTextureAddress, sf::Vector2i mySize, sf::Vector2i myPosition, int n);

//! Destructor
	~Button();

//! Position getter
/*!
	\return position of the button
*/
	sf::Vector2i getPosition();

//! Size getter
/*!
	\return size of the button
*/
	sf::Vector2i getSize();

//! Sprite getter
/*!
	\return the current sprite number
*/
	int getSpriteNumber();

//! Check click
/*!
	checks if button was clicked
	\return true if the button was clicked
*/
	bool checkClick();

//! Check click
/*!
	checks if button is hovered by the moused
	\return true if the button is being hovered
*/
	bool checkHover();

//! Set position
/*!
	sets the position of the button to a new one
	\param mPosition the target position as an SFML 2D vector of integers
*/
	void setPosition(sf::Vector2i mPosition);

//! Set size
/*!
	changes the size of the button
	\param mSize the new size of the button
*/
	void setSize(sf::Vector2i mSize);

//! Display function
/*!
	Displays the button at the current sprite number at the right size and position
	\param w the current RenderWindow in which the button has to be displayed
*/
	void draw(sf::RenderWindow& w); 

//! Hovering check function
/*!
	Will check in a given window whether or not the button is hovered.
	\param w the current RenderWindow in which the hovering is or is not taking place
	\sa bool checkHover();
*/
	bool mouseHover(sf::RenderWindow& w);

//! Resolve Event
/*!
	Handles all events that take place in the button and determine whether it was clicked or not
	\param event an SFML event that will be handled
*/
	void Button::resolveEvent(sf::Event event);

//! Sprite Update
/*!
	Handles the changes in the sprite display
	\param i the wanted sprite number as an integer
*/
	void spriteUpdate(int i);



	void setClickedState(bool mIsClicked);
};