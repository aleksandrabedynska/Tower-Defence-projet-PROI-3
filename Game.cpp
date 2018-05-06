#include "Game.h"

Game::Game() {
	score = 0;
}
int Game::getscore() {
	return score;
}

void Game::addPoint(int x) {
	score = score + x;
}