#include "gtest\include\gtest\gtest.h"
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
	EXPECT_EQ(false,audiomanager.isMute());
}

TEST(AudioManager, mute)
{
	AudioManager audiomanager;
	audiomanager.mute();
	EXPECT_EQ(true,audiomanager.isMute());
}

TEST(AudioManager, play)
{
	AudioManager audiomanager;
	audiomanager.play();
	EXPECT_EQ(false,audiomanager.isMute());
}

//Tests for Path

TEST(Path, construction)
{
	Path path;
	vector<shared_ptr<Tile>> a;
	EXPECT_EQ(a,path);
}

//Tests for computePath()

TEST(Field, computePath)
{
	Field field;
	shared_ptr<Tile> tile1 = field.getTile(80);
	shared_ptr<Tile> tile2 = field.getTile(99);
	const vector<shared_ptr<Tile>> a.push_back(field.getTile(80)).push_back(field.getTile(81)).push_back(field.getTile(82)).push_back(field.getTile(83)).push_back(field.getTile(84)).push_back(field.getTile(85)).push_back(field.getTile(86)).push_back(field.getTile(87)).push_back(field.getTile(88)).push_back(field.getTile(89)).push_back(field.getTile(90)).push_back(field.getTile(91)).push_back(field.getTile(92)).push_back(field.getTile(93)).push_back(field.getTile(94)).push_back(field.getTile(95)).push_back(field.getTile(96)).push_back(field.getTile(97)).push_back(field.getTile(98)).push_back(field.getTile(99));
	/*a.push_back(field.getTile(80));
	a.push_back(field.getTile(81));
	a.push_back(field.getTile(82));
	a.push_back(field.getTile(83));
	a.push_back(field.getTile(84));
	a.push_back(field.getTile(85));
	a.push_back(field.getTile(86));
	a.push_back(field.getTile(87));
	a.push_back(field.getTile(88));
	a.push_back(field.getTile(89));
	a.push_back(field.getTile(90));
	a.push_back(field.getTile(91));
	a.push_back(field.getTile(92));
	a.push_back(field.getTile(93));
	a.push_back(field.getTile(94));
	a.push_back(field.getTile(95));
	a.push_back(field.getTile(96));
	a.push_back(field.getTile(97));
	a.push_back(field.getTile(98));
	a.push_back(field.getTile(99));*/
	EXPECT_EQ(a, field.computePath(tile1,tile2));
	/*shared_ptr<Tile> tile3 = field.getTile(81);
	shared_ptr<Tower> myTower;
	tile3->setTower(myTower);
	vector<shared_ptr<Tile>> b;
	b.push_back(field.getTile(80));
	b.push_back(field.getTile(60));
	b.push_back(field.getTile(61));
	b.push_back(field.getTile(62));
	b.push_back(field.getTile(63));
	b.push_back(field.getTile(64));
	b.push_back(field.getTile(65));
	b.push_back(field.getTile(66));
	b.push_back(field.getTile(67));
	b.push_back(field.getTile(68));
	b.push_back(field.getTile(69));
	b.push_back(field.getTile(70));
	b.push_back(field.getTile(71));
	b.push_back(field.getTile(72));
	b.push_back(field.getTile(73));
	b.push_back(field.getTile(74));
	b.push_back(field.getTile(75));
	b.push_back(field.getTile(76));
	b.push_back(field.getTile(77));
	b.push_back(field.getTile(78));
	b.push_back(field.getTile(79));
	b.push_back(field.getTile(99));
	EXPECT_EQ(b, field.computePath(tile1, tile2));
	shared_ptr<Tile> tile4 = field.getTile(62);
	tile4->setTower(myTower);
	vector<shared_ptr<Tile>> c;
	c.push_back(field.getTile(80));
	c.push_back(field.getTile(100));
	c.push_back(field.getTile(101));
	c.push_back(field.getTile(102));
	c.push_back(field.getTile(103));
	c.push_back(field.getTile(104));
	c.push_back(field.getTile(105));
	c.push_back(field.getTile(106));
	c.push_back(field.getTile(107));
	c.push_back(field.getTile(108));
	c.push_back(field.getTile(109));
	c.push_back(field.getTile(110));
	c.push_back(field.getTile(111));
	c.push_back(field.getTile(112));
	c.push_back(field.getTile(113));
	c.push_back(field.getTile(114));
	c.push_back(field.getTile(115));
	c.push_back(field.getTile(116));
	c.push_back(field.getTile(117));
	c.push_back(field.getTile(118));
	c.push_back(field.getTile(119));
	c.push_back(field.getTile(99));
	EXPECT_EQ(c, field.computePath(tile1, tile2));*/
}

//Tests for tryCross()

TEST(Field, tryCross)
{
	Field field;
	shared_ptr<Tile> tile1 = field.getTile(80);
	shared_ptr<Tile> tile2 = field.getTile(99);
	EXPECT_EQ(true,field.tryCross(tile1, tile2));
	shared_ptr<Tower> myTower; 
	tile1->setTower(myTower);
	EXPECT_EQ(false,field.tryCross(tile1, tile2));
}


int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	string m3;
	cout << "fin des tests unitaires";
	getline(cin, m3);
}