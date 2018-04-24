// TowerDefence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Enemy.h"
#include <cstdlib>
#include <vector>
#include "Tower.h"

int main() {
	srand(time(NULL));
	int windowWidth = 1024;
	int windowHeigth = 768;
	sf::RenderWindow renderWindow(sf::VideoMode(windowWidth, windowHeigth), "Tower Defence");
	sf::Event event;
	//sf::Clock clock;
	Tower tower(100, 100);
	std::vector<Enemy> enemies;
	std::vector<Tower> arrows;
	Enemy enemy(100, 100);
	for (int i = 0; i < 5; ++i) {
		enemy.setPosition(rand() % (windowWidth - 100), rand() % (windowHeigth - 100));
		enemies.push_back(Enemy(enemy));
	}

	float vX, vY;
	int abc = 1;
	while (renderWindow.isOpen()) {
		// Check for all the events that occured since the last frame.
		while (renderWindow.pollEvent(event)) {
			//Handle events here
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}
		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		//std::cout << "Elapsed time since previous frame(microseconds): " << clock.getElapsedTime().asMicroseconds() << std::endl;
		// Start the countdown over.  Think of laps on a stop watch.
		//clock.restart();
		if (abc % 100 == 0) {
			tower.setPosition(100, 100);
			arrows.push_back(Tower(tower));
			tower.searchTarget(enemies);
			tower.aim(enemies);
		}

		for (int i = 0; i < enemies.size(); ++i) {
			enemies[i].update(windowWidth, windowHeigth);
		}
		for (int i = 0; i < arrows.size(); ++i) {
			arrows[i].update();
		}
		//tower.update();
		renderWindow.clear();
		//renderWindow.draw(enemy.getShape());
		for (int i = 0; i < enemies.size(); ++i) {
			renderWindow.draw(enemies[i].getShape());
		}
		for (int i = 0; i < arrows.size(); ++i) {
			renderWindow.draw(arrows[i].getArrowShape());
		}
		renderWindow.draw(tower.getShape());
		renderWindow.draw(tower.getArrowShape());
		
		renderWindow.display();
		abc++;
	}

}
