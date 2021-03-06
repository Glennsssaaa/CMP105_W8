#include "PongBall.h"

PongBall::PongBall() {
	speed = 0.05f;
	setFillColor(sf::Color::Black);
	setPosition(250, 300);
	setSize(sf::Vector2f(25, 25));
	setCollisionBox(sf::FloatRect(0, 0, 10, 10));
	xDir = 1;
	yDir = 1;
}

PongBall::~PongBall() {

}

void PongBall::update(float dt) {
	if (xDir == 1) {
		setPosition(getPosition().x + speed, getPosition().y);
	}
	else if (xDir == 2) {
		setPosition(getPosition().x - speed, getPosition().y);
	}


	if (yDir == 1) {
		setPosition(getPosition().x, getPosition().y + speed);
	}
	else if (yDir == 2) {
		setPosition(getPosition().x, getPosition().y - speed);
	}

	if (getPosition().y < 75) {
		yDir = 1;
	}
	else if (getPosition().y > 425) {
		yDir = 2;
	}

	if (getPosition().x < 50 || getPosition().x > 650) {
		setPosition(250, 300);
	}
}

void PongBall::collisionResponse(GameObject* collider) {
	if (xDir == 1) {
		xDir = 2;
	}
	else if (xDir == 2) {
		xDir = 1;
	}

	if (yDir == 1) {
		yDir = 2;
	}
	else if (yDir == 2) {
		yDir = 1;
	}
}