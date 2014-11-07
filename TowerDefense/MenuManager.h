#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <vector>

class MenuManager
{
private:
	std::vector<Menu*> menuStack;
	Menu* activeMenu;

public:
	static MenuManager* menuManager;

	MenuManager();
	~MenuManager();

	void display(sf::RenderWindow& w);
	void addMenu(Menu*);
	void popMenu();

	std::vector<Menu*>* getMenus();
	Menu* getActiveMenu();

	void setMenus();
	void setActiveMenu();
	void openMenu();
	void closeMenu();
	

	static MenuManager* getMenuManager();

	void resolveEvent();
};