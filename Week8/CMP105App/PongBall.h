#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"

class PongBall : public GameObject
{
public:
	PongBall();
	~PongBall();

	void update(float dt);
	void collisionResponse(GameObject* collider);

private:
	int xDir;
	int yDir;
	float speed;
};

