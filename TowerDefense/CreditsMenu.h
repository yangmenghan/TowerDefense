#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"
#include <string>

class CreditsMenu : public Menu
{
private:
	Button backButton;
	string CREDIT_ADD;
	sf::Font font;

public:
	string getCreditsFile();
	sf::Font getFont();
	void setFont();
	void rollCredits();
};