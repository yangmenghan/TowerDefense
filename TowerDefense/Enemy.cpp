#include "Enemy.h"
#include "Config.h"
#include "LevelManager.h"

using namespace std;

Enemy::Enemy(){
	hp = 0;
	defence = 0;
	bounty = 0;
	scoreValue = 0;
	speed = 0;
	slowed = false;
	maxHp = 0;
	origin_speed = speed;
	slowTime = 0;
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
	origin_speed = speed;
	slowTime = 0;
}

Enemy::~Enemy(){}

float Enemy::getDistanceToTarget(){

	return path.getPath().size();
};

void Enemy::move(){
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
	
};

void Enemy::succed(){
	LevelManager::getLevelManager()->getPlayer()->manageHP(-1);
	dieWithoutBonus();
};

void Enemy::setTile(shared_ptr<Tile> t){
	tile = t;
	if (t != NULL){
		position = t->getPositionPixel();
		updatePath(); 
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
	
	//affect the new speed to the enemy
	if (speed - SLOW_EFFECT > 1)
		speed = speed - SLOW_EFFECT;
};

void Enemy::unSlow(){
	if (speed + SLOW_EFFECT < origin_speed)
		speed = speed + SLOW_EFFECT;
	else if(speed + SLOW_EFFECT == origin_speed)
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
	
	sf::RectangleShape hpBar(sf::Vector2f(50,2));
	hpBar.setFillColor(sf::Color(150, 50, 250, 0));
	
	// create the background of the hpbar
	hpBar.setOutlineThickness(0.8f);
	hpBar.setOutlineColor(sf::Color(255, 255, 255));
	hpBar.setPosition(sf::Vector2f(position.x, position.y + TILE_HEIGHT));

	//create the fill of the hpBar
	sf::RectangleShape hpBarFill(sf::Vector2f((50 * (float)hp) / (float)maxHp, 2));
	hpBarFill.setFillColor(sf::Color(26, 255, 83));
	hpBarFill.setPosition(sf::Vector2f(position.x, position.y + TILE_HEIGHT));
	
	w.draw(hpBarFill);
	w.draw(hpBar);

	w.draw(sprite);
}

