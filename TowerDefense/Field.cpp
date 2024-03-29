#include"Field.h"
#include "LevelManager.h"

//Constructors and destroyers
Field::Field()
{
	width = TILE_WIDTH * TILE_NUM_HOR;
	height = TILE_HEIGHT * TILE_NUM_VER;
	numTileHor = TILE_NUM_HOR;
	numTileVer = TILE_NUM_VER;
	for (int i = 0; i < TILE_NUM_HOR*TILE_NUM_VER; i++)
	{
		tilesMap.emplace_back(make_shared<Tile>(i % TILE_NUM_VER, i / TILE_NUM_VER));	//construct the map of tiles
	}
	startTile = *tilesMap[NUM_START_TILE];
	endTile = *tilesMap[NUM_END_TILE];
	sf::FloatRect bounding(50, 50, TILE_NUM_HOR*TILE_WIDTH, TILE_NUM_VER*TILE_HEIGHT);
	boundingBox = bounding;
}

Field::~Field(){}

shared_ptr<Tile> Field::getTile(int n)
{
	return tilesMap[n];
}

shared_ptr<Tile> Field::getTile(sf::Vector2i _position)
{
	return tilesMap[_position.y*TILE_NUM_VER + _position.x];
}

shared_ptr<Tile> Field::getStartTile()
{
	return this->getTile(NUM_START_TILE);
}

shared_ptr<Tile> Field::getEndTile()
{
	return this->getTile(NUM_END_TILE);
}

sf::Sprite Field::getSprite()
{
	return sprite;
}

//Setters

void Field::setSprite(sf::Sprite mySprite)
{
	sprite = mySprite;
}

//Functions
bool Field::checkHover()
{
	return isHovered;
}

bool Field::mouseHover(sf::RenderWindow& w)
{
	sf::Vector2f mousePosition((float)sf::Mouse::getPosition(w).x, (float)sf::Mouse::getPosition(w).y);

	if (boundingBox.contains(mousePosition))
	{
		isHovered = true;
	}
	else
	{
		isHovered = false;
	}

	return isHovered;
}

void Field::resolveEvent(sf::Event event)
{
	for (auto t : tilesMap)
	{
		if (t->checkHover())
			t->resolveEvent(event);
	}
}

void Field::draw(sf::RenderWindow& w)
{	
	mouseHover(w);	
	for (shared_ptr<Tile> t : tilesMap){	
		t->draw(w);
	}
}

Path Field::computePath(shared_ptr<Tile> tile1, shared_ptr<Tile> tile2)	//algorithme de Dijkstra
{
	sf::Vector2i vec1 = tile1->getPosition();
	sf::Vector2i vec2 = tile2->getPosition();
	int m = vec1.x + vec1.y * TILE_NUM_VER;  //  start tile
	int n = vec2.x + vec2.y * TILE_NUM_VER;  //  destination tile

	int t[TILE_NUM][TILE_NUM];		//build matrice of graph (TILE_NUM_HOR*TILE_NUM_VER, TILE_NUM_HOR*TILE_NUM_VER Tiles)

	for (int i = 0; i < TILE_NUM_HOR*TILE_NUM_VER; i++)
	{
		for (int j = 0; j < TILE_NUM_HOR*TILE_NUM_VER; j++)
		{
			if (
				(i == j + 1 && i % TILE_NUM_VER != 0) ||
				(i == j - 1 && j % TILE_NUM_VER != 0) ||
				i == j + TILE_NUM_VER ||
				i == j - TILE_NUM_VER)
			{
				t[i][j] = 1;											// Tile i and Tile j share a side
			}
			else if (i == j){
				t[i][j] = 0;											// Tile i and j are the same tile
			}
			else {
				t[i][j] = 999;											// Tile i and Tile j do not share a side
			}
		}
	}

	for (int k = 0; k < TILE_NUM_HOR*TILE_NUM_VER; k++)
	{
		if (tilesMap.at(k)->hasTower())								// there is a tower on the tile->can't cross
		{
			for (int l = 0; l < TILE_NUM_HOR*TILE_NUM_VER; l++)
			{
				t[k][l] = 999;
				t[l][k] = 999;
			}
		}
	}

	int V[TILE_NUM];									//is in the group
	int D[TILE_NUM];									//distance from m   

	for (int c = 0; c < TILE_NUM_HOR*TILE_NUM_VER; c++)
	{
		D[c] = t[m][c];
		V[c] = 0;
	}

	for (int f = 0; f < TILE_NUM_HOR*TILE_NUM_VER; f++)
	{
		int sum;
		int temp = 999, w = m;
		for (int d = 0; d < TILE_NUM_HOR*TILE_NUM_VER; d++)
		{
			if (V[d] == 0 && D[d] < temp)
			{
				temp = D[d];
				w = d;
			}
		}
		V[w] = 1;														//find the shortest distance
		for (int k = 0; k < TILE_NUM_HOR*TILE_NUM_VER; k++)
		{
			if (V[k] == 0)
			{
				sum = D[w] + t[w][k];
				if (sum < D[k])
				{
					D[k] = sum;
				}
			}
		}																// change the distances
	}

	vector<shared_ptr<Tile>> path;
	if (D[n] == 999)
	{
		return Path(path);
	}
	int time = D[n];
	path.insert(path.begin(), tile2);
	int g = n;
	while (time != 0)
	{
		if ((g > TILE_NUM_VER) && (D[g - TILE_NUM_VER] == time - 1))
		{
			g -= TILE_NUM_VER;
			time -= 1;
			path.insert(path.begin(), tilesMap[g]);
		}
		else if ((g + TILE_NUM_VER < TILE_NUM_VER*TILE_NUM_HOR) && (D[g + TILE_NUM_VER] == time - 1))
		{
			g += TILE_NUM_VER;
			time -= 1;
			path.insert(path.begin(), tilesMap[g]);
		}
		else if ((g % TILE_NUM_VER != 0) && (D[g - 1] == time - 1))
		{
			g -= 1;
			time -= 1;
			path.insert(path.begin(), tilesMap[g]);
		}
		else if (((g + 1) % TILE_NUM_VER != 0) && (D[g + 1] == time - 1))
		{
			g += 1;
			time -= 1;
			path.insert(path.begin(), tilesMap[g]);
		}
	}
	return Path(path);
}
 

bool Field::tryCross(shared_ptr<Tile> _startTile, shared_ptr<Tile> _endTile)
{
	sf::Vector2i vec1 = _startTile->getPosition();
	sf::Vector2i vec2 = _endTile->getPosition();
	int m = vec1.x  + vec1.y * TILE_NUM_VER ;  
	int n = vec2.x  + vec2.y * TILE_NUM_VER ; 

	vector<shared_ptr<Tile>> path = computePath(_startTile, _endTile).getPath();
	if (path.size() == 0)
	{
		return false;
	}

	//try cross for all the enemies on the field
	LevelManager* levelManager = LevelManager::getLevelManager();
	vector<shared_ptr<Enemy>> enemies;
	enemies = levelManager->getEnemies();									//get the list of enemies
	for (int i = 0; i < enemies.size(); i++)
	{
		shared_ptr<Enemy> enemy = enemies[i];
		shared_ptr<Tile> tile = (*enemy).getTile();
		vector<shared_ptr<Tile>> path = computePath(tile, _endTile).getPath();
		if (path.size() == 0)
		{
			return false;
		}												//enemy i can't cross
	}
	
	return true;										//all the enemis on the field and enemies that will appear on the field can cross
}
