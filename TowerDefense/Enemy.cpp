#include "Enemy.h"
#include "Config.h"
#include "LevelManager.h"

/*
private:
int hp;
float defence;
int bounty;
int scoreValue;
int slowTime;
*/

using namespace std;

Enemy::Enemy(){
	hp = 0;
	defence = 0;
	bounty = 0;
	scoreValue = 0;
	speed = 0;
	slowed = false;
	maxHp = 0;
}


Enemy::Enemy(int mHP, float mDefence, int mBounty, int mScoreValue, sf::Sprite mSprite, float mSpeed){
	hp = mHP;
	defence = mDefence;
	bounty = mBounty;
	scoreValue = mScoreValue;
	speed = mSpeed;
	sprite = mSprite;
	slowed = false;
	maxHp = mHP;
}

Enemy::~Enemy(){}

float Enemy::getDistanceToTarget(){

	return path.getPath().size();
};

bool Enemy::move(){
	if (slowTime > 0){
		slowTime--;
	}
	else if(slowed){
		unSlow();
	}

	shared_ptr<Tile> t = path.getPath()[1];

	int gameSpeed = LevelManager::getLevelManager()->getSpeed();


	if(position.x < t->getPositionPixel().x){
		position.x = position.x + min((int)(gameSpeed * speed), t->getPositionPixel().x - position.x);
	}
	else if (position.x > t->getPositionPixel().x){
		position.x = position.x - min((int)(gameSpeed * speed), position.x - t->getPositionPixel().x);
	}
	
	if (position.y < t->getPositionPixel().y){
		position.y = position.y + min((int)(gameSpeed * speed), t->getPositionPixel().y - position.y);
	}
	else if (position.y > t->getPositionPixel().y){
		position.y = position.y - min((int)(gameSpeed * speed), position.y - t->getPositionPixel().y);
	}
	
	if (position.x == t->getPositionPixel().x && position.y == t->getPositionPixel().y){
		setTile(make_shared<Tile>(*t));
	}
	sprite.setPosition(sf::Vector2f(float(position.x), float(position.y)));
	
	return true;
};

void Enemy::succed(){
	LevelManager::getLevelManager()->getPlayer()->manageHP(-1);
	dieWithoutBonus();
};

void Enemy::setTile(shared_ptr<Tile> t){
	tile = t;
	if (t != NULL){
		position = t->getPositionPixel();
		updatePath(); //TODO : just need to remove the previous tile !
	}
}


void Enemy::die(){
	hp = 0;
	LevelManager::getLevelManager()->getPlayer()->manageScore(scoreValue);
	LevelManager::getLevelManager()->getPlayer()->manageMoney(bounty);
};

void Enemy::dieWithoutBonus(){
	hp = 0;
}

void Enemy::slow(int frames){
	slowTime = frames;
	slowed = true;
	if (speed - SLOW_EFFECT > 0)
		speed = speed - SLOW_EFFECT;
};

void Enemy::unSlow(){
	speed = speed + SLOW_EFFECT;
	slowed = false;
};

void Enemy::updatePath(){
	path = LevelManager::getLevelManager()->getField().computePath(tile, LevelManager::getLevelManager()->getField().getEndTile());
}


void Enemy::takeDamage(int damage){
	if (hp - damage > 0)
		hp = hp - damage;
	else
	{
		hp = 0;
	}
};



// Getters and Setters

int Enemy::getHP(){
	return hp;
};
int Enemy::getBounty(){
	return bounty;
};

int Enemy::getScoreValue(){
	return scoreValue;
};
float Enemy::getDefence(){
	return defence;
};

int Enemy::getSlowTime(){
	return slowTime;
};

void Enemy::draw(sf::RenderWindow &w){
	sf::RectangleShape rectangle(sf::Vector2f(50,5));
	rectangle.setFillColor(sf::Color(150, 50, 250, 0));

	// définit un contour orange de 10 pixels d'épaisseur
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(sf::Color(255, 255, 255));
	rectangle.setPosition(sf::Vector2f(position.x, position.y + TILE_HEIGHT));

	sf::RectangleShape rectangle2(sf::Vector2f((50 * (float)hp) / (float)maxHp, 5));
	rectangle2.setFillColor(sf::Color(26, 255, 83));
	rectangle2.setPosition(sf::Vector2f(position.x, position.y + TILE_HEIGHT));

	w.draw(rectangle2);
	w.draw(rectangle);
	w.draw(sprite);
}

