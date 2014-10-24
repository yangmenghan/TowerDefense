#include"Field.h"
#include"Tile.h"

Field::Field()
{
	width = TILE_WIDTH * TILE_NUM_HOR;
	height = TILE_HEIGHT * TILE_NUM_VER;
	numTileHor = TILE_NUM_HOR;
	numTileVer = TILE_NUM_VER;

	for (int i = 0; i < TILE_NUM_HOR*TILE_NUM_VER; i++)
	{
		//Tile tile(i / TILE_NUM_HOR, i % TILE_NUM_HOR);
		//shared_ptr<Tile> pTile = make_shared<Tile>(tile);
		tilesMap.emplace_back(i / TILE_NUM_HOR, i % TILE_NUM_HOR);
	}

	startTile = tilesMap[NUM_START_TILE];
	endTile = tilesMap[NUM_END_TILE];
}

Field::~Field(){};

int Field::getWidth()
{
	return width;
}

int Field::getHeight()
{
	return height;
}

int Field::getNumTileHor()
{
	return numTileHor;
}

int Field::getNumTileVer()
{
	return numTileVer;
}

void Field::draw()
{
	//to do
}

int Field::tempCross(int m, int n)  //Dijkstra
{
int t[200][200]; //build matrice of graph 20*10, 200 Tiles
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			if (i == j + 1 || i == j - 1 || i == j + 10 || i == j - 10)
				t[i][j] = 1; // exist arret{ Tile i, Tile j}
			if (i == j)
				t[i][j] = 0;

			t[i][j] = 999;       // no arret { Tile i, Tile j}
		};                           
	};
	for (int k = 0; k < 200; k++)
	{
		Tile tile(k / 10 , k % 10 );
		if (tile.hasTower() == 1)
		{
			for (int l = 0; l < 200; l++)
			{
				t[k][l] = 999;
				t[l][k] = 999;
			}
		}
	}                  // no path if has tower


	int V[200];  //is in the group
	int D[200];  //distanceV[m] = 1;
	
	for (int c = 0; c <= 200; c++)
	{
		D[c] = t[m][c];
	}

	for (int f = 0; f < 200; f++)
	{
		int sum;
		int temp = 999, w = m;
		for (int d = 0; d < 200; d++)
		{
			if (V[d] == 0 && D[d] < temp)
			{
				temp = D[d];
				w = d;
			}
		}
		V[w] = 1;
		for (int k = 0; k < 200; k++)
		{
			if (V[k] == 0)
			{
				sum = D[w] + t[w][k];
				if (sum < D[k])
				{
					D[k] = sum;
				}
			}
		}
	}
	return D[n];

}

Path Field::computePath(Tile _startTile, Tile _endTile)
{
	sf::Vector2i vec1 = _startTile.getPosition();
	sf::Vector2i vec2 = _endTile.getPosition();
	int m = vec1.x / TILE_WIDTH + vec1.y * 10 / TILE_HEIGHT;  //  point de depart
	int n = vec2.x / TILE_WIDTH + vec2.y * 10 / TILE_HEIGHT; // point d'arrive
	int time = tempCross(m, n);
	vector<Tile> path;
	path[0] = _startTile;
	int g = m;
	for (int r = 1; r < time; r++)
	{
		if (time == tempCross(g + 10, n) + tempCross(m, g + 10))
			g += 10;
		if (time == tempCross(g + 1, n) + tempCross(m, g + 1))
			g += 1;
		if (time == tempCross(g - 1, n) + tempCross(m, g - 1))
			g -= 1;
		Tile tile(g / 10, g % 10);
		path[r] = tile;
	}
	return path;
}


bool Field::tryCross(Tile _startTile, Tile _endTile)
{
	sf::Vector2i vec1 = _startTile.getPosition();
	sf::Vector2i vec2 = _endTile.getPosition();
	int m = vec1.x / TILE_WIDTH + vec1.y * 10 / TILE_HEIGHT;  //  point de depart
	int n = vec2.x / TILE_WIDTH + vec2.y * 10 / TILE_HEIGHT; // point d'arrive
	int time = tempCross(m, n);
	if (time > 200)
		return false;
	return true;
}