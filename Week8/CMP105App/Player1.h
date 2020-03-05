#pragma once
#include "Framework/GameObject.h"
class Player1 : public GameObject
{
public:
	Player1();
	~Player1();

	void update(float dt);
	void handleInput(int dir);

private:
	int direction;
	float speed;
};

