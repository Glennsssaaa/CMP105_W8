#pragma once
#include "Framework/GameObject.h"
class Player2 : public GameObject
{
public:
	Player2();
	~Player2();

	void update(float dt);
	void handleInput(int dir);

private:
	int direction;
	float speed;
};

