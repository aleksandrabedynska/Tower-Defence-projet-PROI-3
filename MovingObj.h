#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "vec2f.h"
#include "Target.h"

using namespace sf;

class MovingObj
{
	Vector2f correctposition;
	//vec2f position;
	//vec2f direction;
	Vector2f position;
	Vector2f direction;
	float speed;
	bool isShot;
	bool hasGold;
	RectangleShape rect;
	int width, height;
	//vec2f home;
	Vector2f home;
public:
	MovingObj(float x, float y);
	void setPosition(int x, int y);
	void setSpeed(float s);
	RectangleShape getShape();
	Vector2f getPosition();
	//vec2f getPosition1();
	//void setBearing(vec2f aim);
	void setBearing(Vector2f aim);
	//vec2f getBearing();
	Vector2f getBearing();
	void update();
	bool reachedTarget(Target target);
	//void setHome(vec2f pos);
	void setHome(Vector2f pos);
	//vec2f getHome();
	Vector2f getHome();
	void changeStatus();
	bool gotShot();
	bool isDead();
	bool giveStatus();
	
	//void swap(MovingObj o2);

	~MovingObj();
};