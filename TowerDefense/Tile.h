#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "Tower.h"
#include "BuildMenu.h"
#include "TowerMenu.h"

class Tile
{
private:
	sf::Vector2f position;//左上角点的位置
	int width;
	int height;
	int cooldown;//剩余的冷却时间，默认为正常状态，值为0.若被污染，倒计时TILE_COOLDOWN_TIME秒恢复
	shared_ptr<Tower> tower;
public:
	//Constructors and destroyers
	Tile();
	Tile(int, int);//x,y position,第x行，第y列，从0开始计数
	~Tile();

	//Getters
	sf::Vector2f getPosition();
	shared_ptr<Tower>  getTower();
	int getCooldowm();

	//Setters
	void setPosition(sf::Vector2f);
	void setTower(shared_ptr<Tower>);
	void setCooldown(int);

	//Functions
	bool isPolluted();
	bool hasTower();
	shared_ptr<BuildMenu> openBuildMenu();
	shared_ptr<TowerMenu> openTowerMenu();

};