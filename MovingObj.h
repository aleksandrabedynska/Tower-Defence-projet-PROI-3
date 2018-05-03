#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "vec2f.h"
#include "Target.h"

using namespace sf;

class MovingObj
{
	vec2f position;
	vec2f direction;
	float speed;
	bool isShot;
	bool hasGold;
	RectangleShape rect;
	int width, height;
	vec2f home;
public:
	MovingObj(float x, float y);
	void setPosition(int x, int y);
	void setSpeed(float s);
	RectangleShape getShape();
	vec2f getPosition();
	void setBearing(vec2f aim);
	vec2f getBearing();
	void update();
	bool reachedTarget(Target target);
	void setHome(vec2f pos);
	vec2f getHome();
	void changeStatus();
	bool gotShot();
	bool isDead();
	
	//void swap(MovingObj o2);

	~MovingObj();
};