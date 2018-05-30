#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Enemy.h"
#include <vector>
#include <math.h>
#include "MovingObj.h"
#include "Target.h"
#include "arrow.h"

using namespace sf;



class Tower
{
private:
	Vector2f towerposition;					//w tych wpolrzednych bedzie wyswietlana wieza
	Vector2f position;						//wspolrzedne strzaly
	Vector2f aimDirNorm, aimDir;			//wektory wskazujce na cel strzaly
	RectangleShape towerShape;				//ksztalt wiezy
	CircleShape arrowShape;					//ksztalt strzaly
	float arrowSpeed;				//predkosc straly
	Vector2f currVelocity;					//predkosc strzaly wektorowa
	int targetIndex;						//numer wroga
	int score;								//punkt jesli trafi
	struct Arrow {
		Vector2f position;
		Vector2f direction;
	};


	//std::vector<Arrow> arrows;
	//Arrow arrow;
	//std::vector<Arrow> arrows;
	
public:
	Tower(float posX, float posY);												//konstruktor
	void searchTarget(std::vector<MovingObj>& enemies, Target target);			//szuka celu najblizej skarbu, jesli ktorys wrog ma skarb to szuka tego najblizej startu
	void aim(std::vector<MovingObj>& enemies);									//celuje w wybrany cel
	void setPosition(float x, float y);											//ustala pozycje wiezy
	RectangleShape getShape();
	Vector2f getPosition();														//zraca pozycje straly
	void update();																//zamina wspolrzednych straly o zadany wektor predkosci
	CircleShape getArrowShape();												
	void destroyEnemy(std::vector<MovingObj>& enemies);							//niszczy wroga w zasiegu strzaly
	int getscore();																
	Vector2f getTowerposition();												//zwraca pozycje wiezy
	void setTowerposition(Vector2f pos);


	/*void createArrows(std::vector<MovingObj>& enemies1, Target treasure);
	void updateArrows();
	int getsizeArrows();
	CircleShape drawarrowShape(int i);*/
};