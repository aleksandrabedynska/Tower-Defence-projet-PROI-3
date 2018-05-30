#include "Game.h"

Game::Game(int h, int d) {
	score = 0;
	lives = 100;
	windowHeigth = h;
	windowWidth = d;
	gold = 0;
}
int Game::getscore() {
	return score;
}

void Game::addPoint(int x) {
	score = score + x;
}

int Game::getLives() {
	return lives;
}

void Game::takeLife() {
	lives = lives - 1;
}

void Game::deleteArrow(std::vector<Tower>& arrows) {

}

void Game::deleteEnemy(std::vector<MovingObj>& enemies) {
	for (int j = 0; j < enemies.size(); ++j) {
		Vector2f currentPos = enemies[j].getPosition();
		if (currentPos.x < -100 || currentPos.y < -100 || currentPos.x > windowWidth + 100 || currentPos.y > windowHeigth + 100) {
			enemies.erase(enemies.begin() + j);
		}
	}
}

int Game::getGold() {
	return gold;
}

void Game::addGold(int x) {
	gold = gold + x;
}

void Game::takeGold() {
	gold = gold - 80;
}