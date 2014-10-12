#include <SFML\Graphics.hpp>

class Menu
{
protected:
	sf::Texture texture;
	sf::Vector2f size;
	sf::Vector2f position;

public:
//Constructor and destructor
	Menu();
	~Menu();

//Setters
	void setSize(sf::Vector2f);
	void setPosition(sf::Vector2f);
	void setTexture(sf::Texture);


//Getters
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	sf::Texture getTexture();

//Functions
	virtual void draw() = 0;
	virtual void close() = 0;
};