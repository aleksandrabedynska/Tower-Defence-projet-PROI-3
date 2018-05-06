#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Game
{
private:
	int score;

public:
	Game();
	int getscore();
	void addPoint(int x);
};