#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Tile
{
private:
	vector<float> position;
	int width;
	int height;
	Tower tower;
	int cooldown;
public:
	Tile();
	~Tile();
	bool isPolluted();
	void openTowerMenu();
	void openBuildMenu();
	void setTower();
	Tower getTower();
};