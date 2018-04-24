#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include "Enemy.h"
#include <vector>
#include <math.h>

using namespace sf;

class Tower
{
private:
	Vector2f position;
	Vector2f aimDirNorm, aimDir;
	RectangleShape towerShape;
	CircleShape arrowShape;
	float arrowSpeed = 3.4f;
	Vector2f currVelocity;
	int targetIndex;

public:
	Tower(int posX, int posY);
	void searchTarget(std::vector<Enemy>& enemies);
	void aim(std::vector<Enemy>& enemies);
	void setPosition(int x, int y);
	RectangleShape getShape();
	Vector2f getPosition();
	void update();
	CircleShape getArrowShape();

	
};