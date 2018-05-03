#pragma once
#include <math.h>

struct vec2f
{
	float x;
	float y;

	vec2f();
	vec2f(float X, float Y);

	float getLength();
	float getQuadLength();

	void normalize();

	void rotate(float angle);			// angle in degrees

	void operator= (vec2f v);

	vec2f operator+ (vec2f v);
	vec2f operator- (vec2f v);

	void operator+= (vec2f v);
	void operator-= (vec2f v);

	vec2f operator* (float s);

};