#include <SFML\Graphics.hpp>

class Menu
{
protected:
	sf::Texture texture;
	float width;
	float height;
	sf::Vector2f position;

public:
	Menu();
	~Menu();
	virtual void draw() = 0;
	virtual void close() = 0;
};