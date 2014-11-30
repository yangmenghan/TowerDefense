#include "BombEnemy.h"
#include "Config.h"
#include "Tile.h"
#include "Field.h"
#include "LevelManager.h"


BombEnemy::BombEnemy() :Enemy(BOMB_ENEMY_HP, BOMB_ENEMY_DEFENCE, BOMB_ENEMY_BOUNTY, BOMB_ENEMY_SCOREVALUE, sf::Sprite(), BOMB_ENEMY_SPEED){

	sf::Texture texture;
	if (!texture.loadFromFile(BOMB_ENEMY_SPRITE_ADD))
	{
		// TODO erreur...
	}

	sprite.setTexture(texture);
};

BombEnemy::BombEnemy(int mHP, float mDefence, int mBounty, int mScoreValue, int mTrigger, sf::Sprite mSprite, float mSpeed)
	:Enemy(mHP, mDefence, mBounty, mScoreValue, mSprite, mSpeed)
{
	trigger = mTrigger;
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
		else {
			timer = BOMB_ENEMY_COUNTDOWN;
			if (hp <= 0){
				explode();
			}
		}
		
	}
	else {
		return move();
		//TODO : verify the syntax
	}
}

void BombEnemy::explode(){
	
	Field f = LevelManager::getLevelManager()->getField();
	vector<Tile*> t = tile.getNeighbor(1);
	t.push_back(&tile);
	for (Tile* tile : t){
		tile->setCooldown(TILE_COOLDOWN);
	}

	vector<shared_ptr<Enemy>> e = LevelManager::getLevelManager()->getEnemies();
	vector<shared_ptr<Enemy>> enemies;
	for (shared_ptr<Enemy> en : e){
		for (Tile* temp_tile : t){
			if (en->getTile().getPosition() == (*temp_tile).getPosition()){
				enemies.push_back(en);
			}
		}

	}

	for (shared_ptr<Enemy> e : enemies){
		e->dieWithoutBonus();
	}

	vector<shared_ptr<Tower>> t2 = LevelManager::getLevelManager()->getTowers();
	vector<shared_ptr<Tower>> towers;
	for (shared_ptr<Tower> temp_tower : t2){
		for (Tile* temp_tile : t){
			if (temp_tower->getTile().getPosition() == (*temp_tile).getPosition()){
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
