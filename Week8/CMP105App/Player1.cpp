#include "Player1.h"

Player1::Player1() {
	speed= 0.2f;
	setFillColor(sf::Color::Red);
	setPosition(100, 300);
	setSize(sf::Vector2f(25, 100));
	setCollisionBox(sf::FloatRect(0, 0, 25, 100));
}

Player1::~Player1() {

}

void Player1::update(float dt) {
	if (direction == 1) {
		setPosition(getPosition().x, getPosition().y - speed);
	}
	else if (direction == 2) {
		setPosition(getPosition().x, getPosition().y + speed);
	}
	else if (direction == 0) {
		setPosition(getPosition().x, getPosition().y);
	}
}

void Player1::handleInput(int dir) {
	if (dir == 1) {
		direction = 1;
	}
	else if (dir == 2) {
		direction = 2;
	}
	else if(dir==0){
		direction = 0;
	}
}