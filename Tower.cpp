#include "stdafx.h"
#include "Tower.h"

Tower::Tower(int posX, int posY) {
	position.x = posX;
	position.y = posY;
	towerShape.setSize(Vector2f(30.f, 30.f));
	towerShape.setPosition(position);
	arrowShape.setRadius(5);
	arrowShape.setPosition(position);
	arrowShape.setFillColor(sf::Color::Blue);
}

Vector2f Tower::getPosition() {
	return position;
}

void Tower::searchTarget(std::vector<Enemy>& enemies) {
	Vector2f dist;
	int length, temp, index;
	dist = getPosition() - enemies[0].getPosition();
	length = sqrt(pow(dist.x, 2) + pow(dist.y, 2));
	temp = length;
	index = 0;
	for (int i = 1; i < enemies.size(); ++i) {
		dist = getPosition() - enemies[i].getPosition();
		length = sqrt(pow(dist.x, 2) + pow(dist.y, 2));
		if (length < temp) {
			temp = length;
			index = i;
		}
	}
	targetIndex = index;
}

RectangleShape Tower::getShape() {
	return towerShape;
}

void Tower::aim(std::vector<Enemy>& enemies) {
	aimDir = enemies[targetIndex].getPosition() - getPosition();
	aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
}

void Tower::update() {
	position.y += aimDirNorm.y*arrowSpeed;
	position.x += aimDirNorm.x*arrowSpeed;
	arrowShape.setPosition(position);
}

CircleShape Tower::getArrowShape() {
	return arrowShape;
}


void Tower::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}