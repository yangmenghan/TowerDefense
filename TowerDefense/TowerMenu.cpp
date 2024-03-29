#include"TowerMenu.h"
#include "Config.h"
#include "Tile.h"
#include "Tower.h"

//Constructors and destroyers

TowerMenu::TowerMenu(){}

TowerMenu::TowerMenu(shared_ptr<Tile> pTile)
{
	tile = shared_ptr<Tile>(pTile);
	sf::Vector2i tilePositionPixel(tile->getPositionPixel());

	sellButton = Button(SELL_BUTTON_TEXTURE, SMALL_BUTTON_SIZE, tilePositionPixel + sf::Vector2i(-BUTTON_WIDTH, 0), 1);
	upgradeButton = Button(UPGRADE_BUTTON_TEXTURE, SMALL_BUTTON_SIZE, tilePositionPixel + sf::Vector2i(BUTTON_WIDTH, 0), 1);


	if (!font.loadFromFile(FONT))
	{
		//error
	}

	upGradePrice.setFont(font);
	upGradePrice.setColor(sf::Color::Green);
	upGradePrice.setString("$" + std::to_string(getTile()->getTower()->getPrice()));
	upGradePrice.setCharacterSize(14);
	upGradePrice.setPosition(sf::Vector2f(upgradeButton.getPosition()));

	sellPrice.setFont(font);
	sellPrice.setColor(sf::Color::Green);
	sellPrice.setString("$" + std::to_string(getTile()->getTower()->getIncome()));
	sellPrice.setCharacterSize(14);
	sellPrice.setPosition(sf::Vector2f(sellButton.getPosition()));
}

TowerMenu::~TowerMenu(){}

//Getters

shared_ptr<Tile> TowerMenu::getTile()
{
	return tile;
}

//Functions

void TowerMenu::resolveEvent(sf::Event event)
{
	if (sellButton.checkHover())
	{
		sellButton.resolveEvent(event);
		if (sellButton.checkClick())
		{
			shared_ptr<Tower> tower = tile->getTower();
			tower->sellTw();
			LevelManager::getLevelManager()->removeTower(tower);
			close();
		}		
	}
	else if (upgradeButton.checkHover())
	{
		upgradeButton.resolveEvent(event);
		if (upgradeButton.checkClick())
		{
			if (LevelManager::getLevelManager()->getPlayer()->getMoney() >= tile->getTower()->getPrice())
				tile->getTower()->upgradeTw();
			close();
		}
	}
	else if (event.type==sf::Event::MouseButtonReleased)
	{
		close();
	}
}

void TowerMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);

	sellButton.mouseHover(w);
	upgradeButton.mouseHover(w);

	sellButton.draw(w);
	upgradeButton.draw(w);

	w.draw(upGradePrice);
	w.draw(sellPrice);
}

void TowerMenu::close()
{
	LevelManager::getLevelManager()->updatePath();
	MenuManager::getMenuManager()->popMenu();
	MenuManager::getMenuManager()->setExistBTMenu(false);
}
