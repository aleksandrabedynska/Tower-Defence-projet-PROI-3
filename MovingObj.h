#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "vec2f.h"
#include "Target.h"

using namespace sf;

class MovingObj
{
	//Vector2f originalPos;
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
	MovingObj(float x, float y);						//konstruktor
	void setPosition(int x, int y);						//ustala pozycje wroga
	void setSpeed(float s);								//ustala predkosc wroga
	RectangleShape getShape();
	Vector2f getPosition();								//zwraca pozycje wroga
	//vec2f getPosition1();
	//void setBearing(vec2f aim);
	void setBearing(Vector2f aim);						//ustala wektor predkosci
	//vec2f getBearing();
	Vector2f getBearing();
	void update();										//przesuwa obiekt o zadany wektor predkosci
	bool reachedTarget(Target target);
	//void setHome(vec2f pos);
	void setHome(Vector2f pos);							//ustala punkt startu
	//vec2f getHome();
	Vector2f getHome();									//zwraca wektor predkosci do punktu startu
	void changeStatus();								//zmienia status wroga(ma skarb czy nie ma)
	bool gotShot();										// czy zestrzelony
	bool isDead();
	bool giveStatus();	
	bool isHome();										//zwraca true jesli obiekt dotarl do punktu startu
	
	//void swap(MovingObj o2);

	~MovingObj();
};