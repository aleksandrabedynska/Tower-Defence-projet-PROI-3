#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
using namespace sf;

class Enemy 
{
private:
	Vector2f position;

	CircleShape enemyShape;

	float xVelocity = .05f;
	float yVelocity = .05f;

public:
	int random();
	Enemy(float startX, float StartY);
	Vector2f getPosition();
	void setPosition(int x, int y);
	CircleShape getShape();
	float getXVelocity();
	float getYVelocity();
	void update(int windowWidth, int windowHeigth);
};