#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "MovingObj.h"
#include "Tower.h"

class Game
{
private:
	int score;							//zdobyte punkty
	int lives;							//pozostale zycia
	int windowWidth;					//szerokosc okna
	int windowHeigth;					//wysokosc okna
	int gold;							//zdobyte zloto

public:
	Game(int h, int d);					//konstruktor
	int getscore();						//zwraca wynik
	int getLives();						//zwraca liczbe zyc
	void addPoint(int x);				//dodaje punkt
	void takeLife();					//odejmuje zycie
	void deleteArrow(std::vector<Tower>& arrows);		//usuwa strzale jesli jest poza ekranem
	void deleteEnemy(std::vector<MovingObj>& enemies);	//usuwa wroga jesli dotarl do celu
	int getGold();										//zwraca ilosc zlota
	void addGold(int x);								//dodaje jeden punkt zlota
	void takeGold();									//zaniera zloto
};

