#pragma once

struct Point
{
	float x;
	float y;

	Point();
	~Point();

};


class Field 
{
	Point center;
	int width;
	int height;

public:
	Field();
	void draw();
	~Field();
};