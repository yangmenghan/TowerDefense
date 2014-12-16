//#include <gtest/gtest.h>
#include "Config.h"
#pragma once
#include "AudioManager.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include <memory>
#include "Tile.h"
#include "Path.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include "Field.h"
#include "LevelManager.h"
#include "NormalTower.h"

using namespace std;


// tests for AudioManager

TEST(AudioManager, construction)
{
	AudioManager audiomanager;
	EXPECT_EQ(audiomanager.isMute(), false);
}

TEST(AudioManager, mute)
{
	AudioManager audiomanager;
	audiomanager.mute();
	EXPECT_EQ(audiomanager.isMute(), true);
}

TEST(AudioManager, play)
{
	AudioManager audiomanager;
	audiomanager.play();
	EXPECT_EQ(audiomanager.isMute(), false);
}

//Tests for Path

TEST(Path, construction)
{
	Path path;
	vector<shared_ptr<Tile>> a;
	EXPECT_EQ(path, a);
}

//Tests for computePath()

TEST(Field, computePath)
{
	Field field;
	shared_ptr<Tile> tile1 = tilesMap[80];
	shared_ptr<Tile> tile2 = tilesMap[99];
	vector<shared_ptr<Tile>> a = (tilesMap[80], tilesMap[81], tilesMap[82], tilesMap[83], tilesMap[84], tilesMap[85], tilesMap[86], tilesMap[87], tilesMap[88], tilesMap[89], tilesMap[90], tilesMap[91], tilesMap[92], tilesMap[93], tilesMap[94], tilesMap[95], tilesMap[96], tilesMap[97], tilesMap[98], tilesMap[99]);
	EXPECT_EQ(field.computePath(tile1,tile2), a);
	Tile tile3 = tilesMap[81];
	shared_ptr<Tower> myTower;
	tile3.setTower(myTower);
	vector<shared_ptr<Tile>> b = (tilesMap[80], tilesMap[60], tilesMap[61], tilesMap[62], tilesMap[63], tilesMap[64], tilesMap[65], tilesMap[66], tilesMap[67], tilesMap[68], tilesMap[69], tilesMap[70], tilesMap[71], tilesMap[72], tilesMap[73], tilesMap[74], tilesMap[75], tilesMap[76], tilesMap[77], tilesMap[78], tilesMap[79],tilesMap[99]);
	EXPECT_EQ(field.computePath(tile1, tile2), b);
	Tile tile4 = tilesMap[62];
	tile4.setTower(myTower);
	vector<shared_ptr<Tile>> c = (tilesMap[80], tilesMap[100], tilesMap[101], tilesMap[102], tilesMap[103], tilesMap[104], tilesMap[105], tilesMap[106], tilesMap[107], tilesMap[108], tilesMap[109], tilesMap[110], tilesMap[111], tilesMap[112], tilesMap[113], tilesMap[114], tilesMap[115], tilesMap[116], tilesMap[117], tilesMap[118], tilesMap[119], tilesMap[99]);
	EXPECT_EQ(field.computePath(tile1, tile2), c);
}

//Tests for tryCross()

TEST(Field, tryCross)
{
	Field field;
	shared_ptr<Tile> tile1 = tilesMap[80];
	shared_ptr<Tile> tile2 = tilesMap[99];
	EXPECT_EQ(field.tryCross(tile1, tile2), true);
	shared_ptr<Tower> myTower; 
	tile1->setTower(myTower);
	EXPECT_EQ(field.tryCross(tile1, tile2), false);
}


int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	string m3;
	cout << "fin des tests unitaires";
	getline(cin, m3);
}