#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Enemy.h"
#include <vector>
#include <math.h>
#include "MovingObj.h"
#include "Target.h"
#include "arrow.h"

using namespace sf;



class Tower
{
private:
	Vector2f towerposition;
	Vector2f position;
	Vector2f aimDirNorm, aimDir;
	RectangleShape towerShape;
	CircleShape arrowShape;
	float arrowSpeed = 1.4f;
	Vector2f currVelocity;
	int targetIndex;
	int score;
	struct Arrow {
		Vector2f position;
		Vector2f direction;
	};
	std::vector<Arrow> arrows;

	//Arrow arrow;
	//std::vector<Arrow> arrows;
	
public:
	Tower(int posX, int posY);
	void searchTarget(std::vector<MovingObj>& enemies, Target target);
	void aim(std::vector<MovingObj>& enemies);
	void setPosition(int x, int y);
	RectangleShape getShape();
	Vector2f getPosition();
	void update();
	CircleShape getArrowShape();
	void destroyEnemy(std::vector<MovingObj>& enemies);
	int getscore();
	Vector2f getTowerposition();


	/*void createArrows(std::vector<MovingObj>& enemies1, Target treasure);
	void updateArrows();
	int getsizeArrows();
	CircleShape drawarrowShape(int i);*/
};