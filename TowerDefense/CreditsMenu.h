#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Button.h"
#include "Config.h"
#include <string>

class CreditsMenu : public Menu
{
private:
	Button backButton;
	string CREDITS_ADD;
	sf::Sprite sprite;

public:
	string getCreditsAddress();
	sf::Sprite getSprite();
	void setSprite(sf::Sprite);
	void rollCredits();
};