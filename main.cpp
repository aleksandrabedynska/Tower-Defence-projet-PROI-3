#include "SFML/Graphics.hpp"
#include <iostream>
#include "Enemy.h"
#include <cstdlib>
#include <vector>
#include "Tower.h"
#include "Target.h"
#include "MovingObj.h"
#include "Game.h"

int main() {
	int x1, y1;
	Vector2f temp;
	srand(time(NULL));
	int windowWidth = 1024;
	int windowHeigth = 768;
	sf::RenderWindow renderWindow(sf::VideoMode(windowWidth, windowHeigth), "Tower Defence");
	sf::Event event;
	Tower tower(100, 100);
	std::vector<Tower> arrows;
	std::vector<std::vector<Tower> > towers;
	towers.push_back(arrows);
	towers[0].push_back(tower);
	Game game;
	Target treasure(windowWidth - 500, windowHeigth - 500); 
	std::vector<MovingObj> enemies1;			

	float vX, vY;
	int abc = 1;
	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}

		renderWindow.clear(sf::Color(0, 153, 0));			

		if (enemies1.size() < 3) {
			for (int i = 0; i < 20; i++)
			{
				MovingObj enemy(rand() % 2000, rand() % 1000);
				enemy.setHome(enemy.getPosition());
				enemy.setSpeed(0.2);
				enemy.setBearing(treasure.getPosition());
				enemies1.push_back(enemy);
			}
		}							

		if (abc == 5000) {
			std::cout << "Podaj pozycje nowej wiezy " << abc << std::endl;
			std::cin >> x1 >> y1;
			towers.push_back(arrows);
			Tower tower1(x1, y1);
			towers[1].push_back(tower1);
		}		



		if (abc % 100 == 0) {
			for (int i = 0; i < towers.size(); i++) {
				temp = towers[i][0].getTowerposition();
				Tower tower2(temp.x, temp.y);
				towers[i].push_back(tower2);
				towers[i][towers[i].size()-1].searchTarget(enemies1, treasure);
				towers[i][towers[i].size()-1].aim(enemies1);
			}
		}
		
		for (int i = 0; i < enemies1.size(); i++)						
		{
			enemies1[i].update();
			if (enemies1[i].reachedTarget(treasure) == true)
			{
				enemies1[i].setBearing(enemies1[i].getHome());
				enemies1[i].changeStatus();
				treasure.changeStatus();
			}

		}

		for (int j = 0; j < towers.size(); ++j) {
			for (int i = 0; i < towers[j].size(); ++i) {
				towers[j][i].update();
				towers[j][i].destroyEnemy(enemies1);
				game.addPoint(towers[0][i].getscore());
			}
		}

		renderWindow.clear();
		for (int j = 0; j < towers.size(); ++j) {
			for (int i = 0; i < towers[j].size(); ++i) {
				renderWindow.draw(towers[j][i].getArrowShape());
				renderWindow.draw(towers[j][i].getShape());
			}
		}
		
		renderWindow.draw(treasure.getShape());
		for (int i = 0; i < enemies1.size(); i++)
		{
			renderWindow.draw(enemies1[i].getShape());
		}												

		renderWindow.display();
		abc++;
	}

}
