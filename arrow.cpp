#include "arrow.h"

Arrow::Arrow() {
	arrowShape.setRadius(5);
	arrowShape.setPosition(position);
	arrowShape.setFillColor(sf::Color::Blue);
}

Vector2f Arrow::getPosition() {
	return position;
}

void Arrow::searchTarget(std::vector<MovingObj>& enemies, Target target) {
	Vector2f dist;
	int length, temp, index, indexg = -1;
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
			index = i;
		}
		std::cout << i << std::endl;
		if (enemies[i].giveStatus() == true) {
			indexg = i;
		}
	}
	if (indexg == -1)
		targetIndex = index;
	else {
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
					indexg = i;
			}
		}
		targetIndex = indexg;
	}

}

void Arrow::aim(std::vector<MovingObj>& enemies) {
	aimDir = enemies[targetIndex].getPosition() - getPosition();
	aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
}

void Arrow::update() {
	position.y += aimDirNorm.y*arrowSpeed;
	position.x += aimDirNorm.x*arrowSpeed;
	arrowShape.setPosition(position);
}

CircleShape Arrow::getArrowShape() {
	return arrowShape;
}


void Arrow::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}