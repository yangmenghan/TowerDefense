#include "Tower.h"
#include "Player.h"
#include "LevelManager.h"
#include <iostream>

using namespace std;

void main()
{
	/*
	Constructor test
	*/

	Tile tile(5,5);
	Tower tower(tile);
	cout << "Position: ( " << tower.getPosition().x << "," << tower.getPosition().y << ")" << endl;
	cout << "Size: (" << tower.getSize().x << "," << tower.getSize().y << ")" << endl;
	cout << "Tile: (" << tower.getTile().getPosition().x << "," << tower.getTile().getPosition().y << ")" << endl;
	cout << "TilePosition: (" << tower.getTile().getPositionPixel().x << "," << tower.getTile().getPositionPixel().y << ")" << endl;

}
