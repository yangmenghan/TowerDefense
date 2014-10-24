#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <vector>

class MenuManager
{
private:
	std::vector<Menu*> menuStack;

public:
	static MenuManager* menuManager;

	MenuManager();
	~MenuManager();

	void display();
	void addMenu(Menu*);
	void popMenu();
	std::vector<Menu*>* getMenus();

	static MenuManager* getMenuManager();

	void resolveEvent();
};