#include <gtest/gtest.h>
#include "MenuManager.h"
#include "Menu.h"
#include "StartMenu.h"
#include "CreditsMenu.h"
#include "GameMenu.h"
#include "Button.h"
#include <vector>
#include <memory>

using namespace std;



TEST(MenuManager, getMenuManager)
{
	MenuManager* menuManagertest = MenuManager::getMenuManager();
	int t = menuManagertest->getCount();
	EXPECT_EQ(t,0);
}


TEST(MenuManager, addMenu)
{
	MenuManager* menuManager = MenuManager::getMenuManager();
	shared_ptr<StartMenu> menu1 = make_shared<StartMenu>();
	shared_ptr<CreditsMenu> menu2 = make_shared<CreditsMenu>();
	menuManager->addMenu(menu1);
	menuManager->addMenu(menu2);
	int t = menuManager->getCount();
	EXPECT_EQ(t, 2);
	EXPECT_EQ(menuManager->getActiveMenu(), menu2);
}

TEST(MenuManager, clearMenuStack)
{
	MenuManager* menuManager = MenuManager::getMenuManager();
	shared_ptr<StartMenu> menu1 = make_shared<StartMenu>();
	shared_ptr<CreditsMenu> menu2 = make_shared<CreditsMenu>();
	menuManager->addMenu(menu1);
	menuManager->addMenu(menu2);
	menuManager->clearMenuStack();
	int t = menuManager->getCount();
	EXPECT_EQ(t, 0);
}

TEST(MenuManager, closeMenu)
{
	MenuManager* menuManager = MenuManager::getMenuManager();
	menuManager->clearMenuStack();
	shared_ptr<StartMenu> menu1 = make_shared<StartMenu>();
	shared_ptr<CreditsMenu> menu2 = make_shared<CreditsMenu>();
	menuManager->addMenu(menu1);
	menuManager->addMenu(menu2);
	menuManager->closeMenu();
	int t = menuManager->getCount();
	EXPECT_EQ(t, 1);
	EXPECT_EQ(menuManager->getActiveMenu(), menu1);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	getchar();
	return 0;
}