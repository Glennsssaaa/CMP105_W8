#include "Squares.h"

Squares::Squares() {
	speed = 0.1f;
}

Squares::~Squares() {

}

void Squares::update(float dt) {
	if (getPosition().x >= 600) {
		direction = 1;
	}
	else if (getPosition().x <= 100) {
		direction = 2;
	}

	if (direction == 1) {
		setPosition(getPosition().x - speed, getPosition().y);
	}
	else if (direction == 2) {
		setPosition(getPosition().x + speed, getPosition().y);
	}
}

void Squares::collisionResponse(GameObject* collider) {
	if (direction == 1) {
		direction = 2;
	}
	else if (direction == 2) {
		direction = 1;
	}
}
