#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <Vector>
#include "Tower.h"
#include "BuildMenu.h"
#include "TowerMenu.h"

class Tile
{
private:
	sf::Vector2i positionPixel;//左上角点的位置
	sf::Vector2i position;
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
	sf::Vector2i getPosition();
	sf::Vector2i getPositionPixel();
	shared_ptr<Tower>  getTower();
	int getCooldowm();
	vector<Tile*> getNeighbor(int);
	Tile* getStartTile();
	Tile* getEndTile();

	//Setters
	void setPosition(sf::Vector2i);
	void setTower(shared_ptr<Tower>);
	void setCooldown(int);

	//Functions	
	bool isPolluted();
	bool hasTower();
	shared_ptr<BuildMenu> openBuildMenu();
	shared_ptr<TowerMenu> openTowerMenu();

};