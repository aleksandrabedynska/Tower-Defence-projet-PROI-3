#include "vec2f.h"

vec2f::vec2f()
{
	x = 0.0f;
	y = 0.0f;
}

vec2f::vec2f(float X, float Y)
{
	x = X;
	y = Y;
}

float vec2f::getLength()
{
	return sqrt(x*x + y*y);
	return 0.0f;
}

float vec2f::getQuadLength()
{
	return (x*x + y*y);
	return 0.0f;
}

void vec2f::normalize()
{
	float length = this->getLength();

	x = x / length;
	y = y / length;
}

void vec2f::rotate(float angle)
{
	float radian = angle * (3.1415926f / 180.0f);

	float cosinus = cos(radian);
	float sinus = sin(radian);

	float x2;
	float y2;

	x2 = cosinus * x - sinus * y;
	y2 = sinus * x + cosinus * y;

	x = x2;
	y = y2;
}

void vec2f::operator=(vec2f v)
{
	x = v.x;
	y = v.y;
}

vec2f vec2f::operator+(vec2f v)
{
	return vec2f(x + v.x, y + v.y);
}

vec2f vec2f::operator-(vec2f v)
{
	return vec2f(x - v.x, y - v.y);
}

void vec2f::operator+=(vec2f v)
{
	x += v.x;
	y += v.y;
}

void vec2f::operator-=(vec2f v)
{
	x -= v.x;
	y -= v.y;
}

vec2f vec2f::operator*(float s)
{
	return vec2f(x*s, y*s);
}
