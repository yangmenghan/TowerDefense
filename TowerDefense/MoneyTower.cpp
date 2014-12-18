#include "MoneyTower.h"


MoneyTower::MoneyTower(shared_ptr<Tile> mTile)
	:Tower(mTile)
{
	for (int i = 0; i < 3; i++)
	{
		damage[i] = MONEY_TOWER_DAMAGE[i];
		income[i] = MONEY_TOWER_INCOME[i];
		range[i] = MONEY_TOWER_RANGE[i];
		speed[i] = MONEY_TOWER_SPEED[i];
	}
	timer = speed[level - 1];
	price = MONEY_TOWER_PRICE;

	if (!texture.loadFromFile(MONEY_TOWER_SPRITE_ADD))
	{
		// TODO erreur...
	}
	setTowerTexture();
	
	attack = make_shared<NormalAttack>();
	setAttack();
	setRangeCircle();

	if (!font.loadFromFile(FONT))
	{
		//TODO erreur
	}
	moneyGenerationDisplay.setFont(font);
	moneyGenerationDisplay.setCharacterSize(14);
	moneyGenerationDisplay.setColor(sf::Color::Green);
	moneyGenerationDisplay.setPosition(sf::Vector2f(float(tile->getPositionPixel().x - 5), float(tile->getPositionPixel().y + 5)));
}

void MoneyTower::doAttack(sf::RenderWindow& w)
{
	generateMoney();
}

/*
Generate money in a frequency defined by timer
*/

void MoneyTower::generateMoney()
{
	if (timer < 10 / LevelManager::getLevelManager()->getSpeed())
	{
		sprite.setColor(sf::Color(255, 255, 0, 100));
		if (timer == 0)
		{
			LevelManager::getLevelManager()->getPlayer()->manageMoney(MONEY_TOWER_GENERATION_UNIT[level - 1]);
			timer = speed[level - 1] * LevelManager::getLevelManager()->getSpeed();
			displayTimer = 0;
		}
		else
			timer--;
	}
	else
	{
		sprite.setColor(sf::Color(255, 255, 255, 255));
		timer--;
	}
}

void MoneyTower::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
	displayGeneratedMoney();
	w.draw(moneyGenerationDisplay);
}

void MoneyTower::displayGeneratedMoney()
{
	if (displayTimer == 0)
	{
		moneyGenerationDisplay.setPosition(sf::Vector2f(float(tile->getPositionPixel().x - 5), float(tile->getPositionPixel().y + 5)));
		moneyGenerationDisplay.setString("+" + to_string(MONEY_TOWER_GENERATION_UNIT[level - 1]) + "$");
		displayTimer++;
	}
	else if (displayTimer == 15)
	{
		moneyGenerationDisplay.setString("");
	}
	else
	{
		moneyGenerationDisplay.setPosition(moneyGenerationDisplay.getPosition() + sf::Vector2f(0, -1));
		displayTimer++;
	}
}