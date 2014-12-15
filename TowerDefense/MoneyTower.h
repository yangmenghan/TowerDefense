#pragma once
#include "Tower.h"
#include "NormalAttack.h"

class MoneyTower :
	public Tower
{
private:
	sf::Text moneyGenerationDisplay;
	sf::Font font;
	int displayTimer;

public:
	MoneyTower(shared_ptr<Tile> mTile);
	MoneyTower(float mDamage, int mPrice, int mLevel, float mRange, float mSpeed, sf::Sprite mSprite);
	virtual ~MoneyTower(){};

	void generateMoney();
	void doAttack(sf::RenderWindow& w) override;
	void draw(sf::RenderWindow& w) override;
	void displayGeneratedMoney();
};

