#pragma once
#include <SFML/Graphics.hpp>
#include "vec2f.h"
using namespace sf;
class Target
{
	vec2f position;
	int width;
	int height;
	int gold;	// number of gold left at treasure
	RectangleShape rect;
public:

	Target(float x, float y);

	vec2f getPosition();
	int getWidth();
	int getHeight();
	int goldLeft();
	void setPosition(float x, float y);
	RectangleShape getShape();
	void changeStatus();
	void setGoldNumber(int g);
	void update();
	~Target();
};