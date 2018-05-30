
#include "Enemy.h"

Enemy::Enemy(float startX, float startY) {
	position.x = startX;
	position.y = startY;
	enemyShape.setRadius(10);
	enemyShape.setPosition(position);
}

Vector2f Enemy::getPosition()
{
	return position;
}
void Enemy::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

CircleShape Enemy::getShape()
{
	return enemyShape;
}

float Enemy::getXVelocity()
{
	return xVelocity;
}
float Enemy::getYVelocity()
{
	return yVelocity;
}

void Enemy::update(int windowWidth, int windowHeigth)
{
	// Update the enemy position variables
	if (position.x < 10 || position.x > windowWidth - 10) {
		xVelocity = (-1)*xVelocity;
	}
	else if (position.y < 10 || position.y > windowHeigth - 10) {
		yVelocity = (-1)*yVelocity;
	}
	position.y += yVelocity;
	position.x += xVelocity;
	enemyShape.setPosition(position);
}

int Enemy::random() {
	srand(time(NULL));
	return rand()%4;
}
