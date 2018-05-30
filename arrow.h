#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Enemy.h"
#include <vector>
#include <math.h>
#include "MovingObj.h"
#include "Target.h"
#include "Tower.h"

using namespace sf;

class Arrow
{
private:
	Vector2f position;
	Vector2f aimDirNorm, aimDir;
	CircleShape arrowShape;
	float arrowSpeed = 3.4f;
	Vector2f currVelocity;
	int targetIndex;

public:
	Arrow();
	void searchTarget(std::vector<MovingObj>& enemies, Target target);
	void aim(std::vector<MovingObj>& enemies);
	void setPosition(int x, int y);
	Vector2f getPosition();
	void update();
	CircleShape getArrowShape();

};
