#include <SFML/Graphics.hpp>
//#include <cstdlib>
#include <vector>
#include <iostream>
#include "Target.h"
#include "MovingObj.h"


static int winWidth = 1800;
static int winHeight = 900;

using std::vector;
using namespace sf;
using std::cout;
using std::endl;
int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(winWidth, winHeight,32), "SFML");
	
	Target treasure(winWidth - 100, winHeight - 100);
	
	vector<MovingObj> enemies;
	for (int i = 0; i < 10; i++) 
	{
		MovingObj enemy(rand() % 2000, rand() % 1000);
		enemy.setHome(enemy.getPosition());
		enemy.setSpeed(1);
		enemy.setBearing(treasure.getPosition());
		enemies.push_back(enemy);
	}
	for (int i = 0; i < enemies.size(); i++)
	{
		cout << "enemy init " << i << endl;
	}


	
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle)
				window.close();

		}
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i].update();
			if (enemies[i].reachedTarget(treasure) == true)
			{
				enemies[i].setBearing(enemies[i].getHome());
				enemies[i].changeStatus();
				treasure.changeStatus();
				cout << "gold left" << treasure.goldLeft() << endl;
				
			}

		}
		enemies[2].gotShot();

	/*
		for (int i = 0; i < enemies.size(); i++)
		{
			cout << "enemy left " << i << endl;
		}
	*/
		
		window.clear(sf::Color(0, 153, 0));

		window.draw(treasure.getShape());
		for (int i = 0; i < enemies.size(); i++)
		{
			window.draw(enemies[i].getShape());
		}
		window.display();
	}
	 
	return 0;
}