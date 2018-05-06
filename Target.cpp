#include "Target.h"

Target::Target(float x, float y)
{
	position.x = x;
	position.y = y;
	height = 30;
	width = 30;
	gold = 15;
	rect.setSize(Vector2f(width, height));
	rect.setPosition(position.x,position.y);
	rect.setFillColor(Color::Yellow);

}

Vector2f Target::getPosition()
{
	return position;
}

int Target::getWidth()
{
	return width;
}

int Target::getHeight()
{
	return height;
}

int Target::goldLeft()
{
	return gold;
}

void Target::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

RectangleShape Target::getShape()
{
	return rect;
}

void Target::changeStatus()
{
	gold--;
}

void Target::setGoldNumber(int g)
{
	gold = g;
}

void Target::update()
{

}

Target::~Target()
{
}
