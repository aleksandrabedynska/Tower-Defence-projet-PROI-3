#include "Tower.h"

Tower::Tower(float posX, float posY) {
	arrowSpeed = 1.4f;
	towerposition.x = posX;
	towerposition.y = posY;
	position.x = posX;
	position.y = posY;
	towerShape.setSize(Vector2f(30.f, 30.f));
	towerShape.setPosition(position);
	arrowShape.setRadius(5);
	arrowShape.setPosition(position);
	arrowShape.setFillColor(sf::Color::Blue);
	score = 0;
	//arrow.setPosition(position.x, position.y);
}

Vector2f Tower::getPosition() {
	return position;
}

void Tower::searchTarget(std::vector<MovingObj>& enemies, Target target) {
	Vector2f dist;
	float length, temp;
	int index, indexg = -1;															//pomocnicze zmienne do przechowywania indeksow wrogow
	dist = target.getPosition() - enemies[0].getPosition();
	length = sqrt(pow(dist.x, 2) + pow(dist.y, 2));
	temp = length;
	index = 0;
	if (enemies[0].giveStatus() == true)											
		indexg = 0;
	for (int i = 1; i < enemies.size(); ++i) {
		dist = target.getPosition() - enemies[i].getPosition();
		length = sqrt(pow(dist.x, 2) + pow(dist.y, 2));
		if (length < temp) {
			temp = length;
			index = i;																//zapisuje indeks wroga najblizej skarbu
		}
		if (enemies[i].giveStatus() == true) {
			indexg = i;																//jesli ktorys z wrogow ma skarb to zmienia sie wartosc indexg
		}
	}
	if (indexg == -1)
		targetIndex = index;
	else {																			//jesli ktorys z wrogow ma skarb to poszukiwany jest wrog ze skarbem najblizej miejsca staru
		dist = enemies[0].getHome() - enemies[0].getPosition();
		length = sqrt(pow(dist.x, 2) + pow(dist.y, 2));
		temp = length;
		index = 0;
		if (enemies[0].giveStatus() == true)
			indexg = 0;
		for (int i = 1; i < enemies.size(); ++i) {
			dist = enemies[i].getHome() - enemies[i].getPosition();
			length = sqrt(pow(dist.x, 2) + pow(dist.y, 2));
			if (length < temp) {
				temp = length;
				index = i;
				if (enemies[i].giveStatus() == true)
					indexg = i;														//indeks wroga ze skarbem najblizej miejsca startu
			}
		}
		targetIndex = indexg;
	}
		
}

RectangleShape Tower::getShape() {
	towerShape.setPosition(towerposition);
	return towerShape;
}

void Tower::aim(std::vector<MovingObj>& enemies) {
	aimDir = enemies[targetIndex].getPosition() - getPosition();
	aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
}

void Tower::update() {
	position.y += aimDirNorm.y*arrowSpeed;
	position.x += aimDirNorm.x*arrowSpeed;
	arrowShape.setPosition(position);
	score = 0;													//punkty sa zdobywane tylko wtedy gdy strzala jest w poblizu wroga
}

CircleShape Tower::getArrowShape() {
	return arrowShape;
}

void Tower::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

void Tower::destroyEnemy(std::vector<MovingObj>& enemies) {
	for (int j = 0; j < enemies.size(); ++j) {
		Vector2f dist = getPosition() - enemies[j].getPosition();
		double length = sqrt(pow(dist.x, 2) + pow(dist.y, 2));
		if (length < 20) {
			enemies.erase(enemies.begin() + j);
			score = 1;														//jesli jest w odleglosci <20 od wroga to wektor wrogow skraca sie o tego wroga i dana strzala moze zdobyc punkt
		}
	}
}
	
int Tower::getscore() {
	return score;									//zwraca punkt
}

Vector2f Tower::getTowerposition() {
	return towerposition;
}

void Tower::setTowerposition(Vector2f pos) {
	towerposition = pos;
}


/*void Tower::createArrows(std::vector<MovingObj>& enemies1,Target treasure) {
	arrows.push_back(Arrow(arrow));
	arrow.searchTarget(enemies1, treasure);
	arrow.aim(enemies1);
}

void Tower::updateArrows() {
	for (int i = 0; i < arrows.size(); ++i) {
		arrows[i].update();
	}

}

int Tower::getsizeArrows() {
	return arrows.size();
}

CircleShape Tower::drawarrowShape(int i) {
	return arrows[i].getArrowShape();
}*/