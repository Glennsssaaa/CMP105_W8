#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	square1.setFillColor(sf::Color::Blue);
	square1.setPosition(600, 200);
	square1.setSize(sf::Vector2f(50, 50));
	square1.setCollisionBox(sf::FloatRect(0, 0, 50, 50));

	square2.setFillColor(sf::Color::Red);
	square2.setPosition(100, 200);
	square2.setSize(sf::Vector2f(50, 50));
	square2.setCollisionBox(sf::FloatRect(0, 0, 50, 50));

	ball1Texture.loadFromFile("gfx/Beach_Ball.png");
	ball1.setTexture(&ball1Texture);
	ball2.setTexture(&ball1Texture);

	ball1.setPosition(600, 300);
	ball1.setSize(sf::Vector2f(50, 50));
	ball1.setCollisionBox(sf::FloatRect(0, 0, 50, 50));

	ball2.setPosition(100, 300);
	ball2.setSize(sf::Vector2f(50, 50));
	ball2.setCollisionBox(sf::FloatRect(0, 0, 50, 50));

	
}

Level::~Level()
{

}

int mousePos;
// handle user input
void Level::handleInput(float dt)
{
	if (player1.getPosition().y >= 100){
		if (input->isKeyDown(sf::Keyboard::W)) {
			player1.handleInput(1);
		}
	}
	else if(player1.getPosition().y < 50){
		player1.setPosition(player1.getPosition().x, 50);
	}

	if (player1.getPosition().y <= 600){
		if (input->isKeyDown(sf::Keyboard::S)) {
			player1.handleInput(2);
		}
	}
	else if(player1.getPosition().y > 600){
		player1.setPosition(player1.getPosition().x, 600);
	}

	if (!(input->isKeyDown(sf::Keyboard::W)) && !(input->isKeyDown(sf::Keyboard::S))) {
		player1.handleInput(0);
	}


	mousePos = sf::Mouse::getPosition().y;

	if (player2.getPosition().y >= 50) {
		if (mousePos <= player2.getPosition().y + 100) {
			player2.handleInput(1);
		}
	}
	else if (player2.getPosition().y < 50) {
		player2.setPosition(player2.getPosition().x, 50);
	}

	if (player2.getPosition().y <= 600) {
		if (mousePos > player2.getPosition().y + 100) {
			player2.handleInput(2);
		}
	}
	else if (player2.getPosition().y > 600) {
		player2.setPosition(player2.getPosition().x, 600);
	}

}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	ball2.update(dt);

	square1.update(dt);
	square2.update(dt);

	player1.update(dt);
	player2.update(dt);

	pongball.update(dt);

	if (Collision::checkBoundingCircle(&ball1, &ball2)) {
		ball1.collisionResponse(NULL);
		ball2.collisionResponse(NULL);
	}

	if (Collision::checkBoundingBox(&square1, &square2)) {
		square1.collisionResponse(NULL);
		square2.collisionResponse(NULL);
	}

	if (Collision::checkBoundingBox(&pongball, &player1)) {
		pongball.collisionResponse(NULL);
	}

	if (Collision::checkBoundingBox(&pongball, &player2)) {
		pongball.collisionResponse(NULL);
	}

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(ball2);

	window->draw(square1);
	window->draw(square2);

	window->draw(player1);
	window->draw(player2);
	window->draw(pongball);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}