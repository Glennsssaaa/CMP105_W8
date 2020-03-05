#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Ball.h"
#include "Framework/Collision.h"
#include "Squares.h"
#include "Player1.h"
#include "Player2.h"
#include "PongBall.h"

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	Squares square1;
	Squares square2;
	Ball ball1;
	Ball ball2;
	sf::Texture ball1Texture;
	Player1 player1;
	Player2 player2;
	PongBall pongball;
};