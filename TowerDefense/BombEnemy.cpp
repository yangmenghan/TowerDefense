#include "BombEnemy.h"
#include "Config.h"
#include "Tile.h"
#include "Field.h"
#include "LevelManager.h"


BombEnemy::BombEnemy() :Enemy(BOMB_ENEMY_HP, BOMB_ENEMY_DEFENCE, BOMB_ENEMY_BOUNTY, BOMB_ENEMY_SCOREVALUE, sf::Sprite(), BOMB_ENEMY_SPEED){

	timer = BOMB_ENEMY_COUNTDOWN;
	trigger = BOMB_ENEMY_TRIGGER;
	if (!texture.loadFromFile(BOMB_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(TILE_WIDTH, TILE_HEIGHT)));
	sprite.setPosition(sf::Vector2f(float(position.x + TILE_WIDTH), float(position.y + TILE_HEIGHT)));
	
};

BombEnemy::BombEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, int mTrigger, sf::Sprite mSprite, float mSpeed)
	:Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed)
{
	trigger = mTrigger; 
	timer = BOMB_ENEMY_COUNTDOWN;
	if (!texture.loadFromFile(BOMB_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(TILE_WIDTH, TILE_HEIGHT)));
	sprite.setPosition(sf::Vector2f(float(position.x + TILE_WIDTH), float(position.y + TILE_HEIGHT)));
};

int BombEnemy::getTrigger(){
	return trigger;
};

int BombEnemy::getTimer(){
	return timer;
};

bool BombEnemy::move(){
	if (hp <= trigger){
		if (timer > 0){
			timer--;
		}
		else  {
			if (hp > 0){
				explode();
			}
		}
		
	}
	else {
		return Enemy::move();
		//TODO : verify the syntax
	}
}

void BombEnemy::explode(){
	
	Field f = LevelManager::getLevelManager()->getField();
	vector<shared_ptr<Tile>> t = tile->getNeighbor(1);
	t.push_back(tile);
	for (shared_ptr<Tile> tile : t){
		tile->setCooldown();
	}

	vector<shared_ptr<Enemy>> e = LevelManager::getLevelManager()->getEnemies();
	vector<shared_ptr<Enemy>> enemies;

	for (shared_ptr<Enemy> en : e){
		for (shared_ptr<Tile>temp_tile : t){
			if (en->getTile()->getPosition() == temp_tile->getPosition() && &(*en) != this){
				enemies.push_back(en);
			}
		}

	}

	for (shared_ptr<Enemy> e : enemies){
		e->dieWithoutBonus();
		LevelManager::getLevelManager()->removeEnemy(e);
	}

	vector<shared_ptr<Tower>> t2 = LevelManager::getLevelManager()->getTowers();
	vector<shared_ptr<Tower>> towers;

	for (shared_ptr<Tower> temp_tower : t2){
		for (shared_ptr<Tile> temp_tile : t){
			if (temp_tower->getTile()->getPosition() == temp_tile->getPosition()){
				towers.push_back(temp_tower);
			}
		}

	}

	for (shared_ptr<Tower> t : towers){
		t->downgradeTw();
	}

	dieWithoutBonus();
};

void BombEnemy::TriggerCountDown(){

};

void BombEnemy::checkCountDown(){
};
