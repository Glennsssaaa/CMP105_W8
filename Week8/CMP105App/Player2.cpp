#include "Player2.h"

Player2::Player2() {
	speed = 0.2f;
	setFillColor(sf::Color::Blue);
	setPosition(600, 300);
	setSize(sf::Vector2f(25, 100));
	setCollisionBox(sf::FloatRect(0, 0, 25, 100));
}

Player2::~Player2() {

}

void Player2::update(float dt) {
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

void Player2::handleInput(int dir) {
	if (dir == 1) {
		direction = 1;
	}
	else if (dir == 2) {
		direction = 2;
	}
	else if (dir == 0) {
		direction = 0;
	}
}