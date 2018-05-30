#include "SFML/Graphics.hpp"
#include <iostream>
#include "Enemy.h"
#include <cstdlib>
#include <vector>
#include "Tower.h"
#include "Target.h"
#include "MovingObj.h"
#include "Game.h"
#include <string>

//rysowanie obiektow
void drawObjects(std::vector<std::vector<Tower> >& towers, sf::RenderWindow& renderWindow, Target& treasure, std::vector<MovingObj>& enemies, int windowWidth, int windowHeigth, Game& game, sf::Font font) {
	//std::cout << "ilosc worgow = " << enemies.size() << std::endl;
	for (int j = 0; j < towers.size(); ++j) {
		//std::cout << "towers.size = " << towers.size() << std::endl;
		//std::cout << "towers[" << j << "].size = " << towers[j].size() << std::endl;
		for (int i = 0; i < towers[j].size(); ++i) {
			renderWindow.draw(towers[j][i].getArrowShape());
			//std::cout << "narysowau szczaue" << std::endl;
			renderWindow.draw(towers[j][i].getShape());
			//std::cout << "narysowau wroga" << std::endl;
			if (towers[j][i].getPosition().x < 0 || towers[j][i].getPosition().y < 0 || towers[j][i].getPosition().x > windowWidth || towers[j][i].getPosition().y > windowHeigth) {
				//std::cout << "erease tower[" << j << "][" << i << "]" << std::endl;
				towers[j].erase(towers[j].begin() + i);
			}
		}
	}

	renderWindow.draw(treasure.getShape());
	if (game.getGold() >= 80) {
		sf::Text text1;
		text1.setFont(font);
		text1.setString("CREATE NEW TOWER");
		text1.setCharacterSize(50);
		text1.setPosition(static_cast<float>(windowHeigth / 2), static_cast<float>(windowWidth / 2));
		renderWindow.draw(text1);
	}

	for (int i = 0; i < enemies.size(); i++)
	{
		renderWindow.draw(enemies[i].getShape());
	}
}

//wywoluje nowa fale wrogow
void newWave(std::vector<MovingObj>& enemies,int windowWidth,int windowHeigth, Target& treasure, int towerNumber) {
	if (enemies.size() < 3) {		//jesli wrogow na planszy zostalo 3 to uruchamiana jest nowa fala
		for (int i = 0; i < 20*(1+towerNumber*0.1); i++)
		{
			float x = (float)(rand() % windowWidth);
			float y = (float)(rand() % windowHeigth);
			MovingObj enemy(x, y);		//umieszczanie w losowych miejscach na planszy
			enemy.setHome(enemy.getPosition());		
			float speed = (float)(0.2*(towerNumber*0.5 + 1));
			enemy.setSpeed(speed);
			enemy.setBearing(treasure.getPosition());							//skierowanie w strone skarbu
			enemies.push_back(enemy);											//dodanie do wektora
		}
	}
}

//stawia nowa wieze
void createTower(Game& game, std::vector<Tower>& arrows, sf::RenderWindow& renderWindow, std::vector<std::vector<Tower> >& towers, int &towerNumber) {
	if (game.getGold() >= 80) {								//jesli gold > 30 mozna dodac nastepna wieze
		bool isPressed = true;
		towers.push_back(arrows);											//nowy wektor w wektorze towers
		sf::Vector2i mousePos;
		while (isPressed) {													//petla konczy sie po nacisnieciu lpm
			mousePos = sf::Mouse::getPosition(renderWindow);
			Tower tower1(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			isPressed = !(sf::Mouse::isButtonPressed(sf::Mouse::Left));
		}
		Tower tower1(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		towers[towerNumber].push_back(tower1);
		towerNumber++;
		game.takeGold();													//potraca koszt wiezy
	}
}

//generuje nowe strzaly
void shoot(int abc, std::vector<std::vector<Tower> >& towers, std::vector<MovingObj>& enemies, Target& treasure) {
	Vector2f temp;
	if (abc % 100 == 0) {
		for (int i = 0; i < towers.size(); i++) {
			temp = towers[i][0].getTowerposition();
			Tower tower2(temp.x, temp.y);
			towers[i].push_back(tower2);
			towers[i][towers[i].size() - 1].searchTarget(enemies, treasure);
			towers[i][towers[i].size() - 1].aim(enemies);
		}
	}
}

//sprawdza czy wrogowie dotarli do skarbu, jesli tak to zmienia ich status
void enemiesStatus(std::vector<MovingObj>& enemies, Target& treasure) {
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].update();
		if (enemies[i].reachedTarget(treasure) == true)
		{
			enemies[i].setBearing(enemies[i].getHome());
			enemies[i].changeStatus();
			treasure.changeStatus();
		}
	}
}

//niszczenie wrogow
void destroyEnemy(std::vector<std::vector<Tower> >& towers, Game& game, std::vector<MovingObj>& enemies) {
	for (int j = 0; j < towers.size(); ++j) {
		for (int i = 0; i < towers[j].size(); ++i) {
			towers[j][i].update();
			towers[j][i].destroyEnemy(enemies);
			game.addPoint(towers[j][i].getscore());
			game.addGold(towers[j][i].getscore());
		}
	}
}

//usuwanie wrogow i odejmowanie zycia jesli wrog wrocil na start
void enemyHome(std::vector<MovingObj>& enemies, Game& game) {
	for (int i = 0; i < enemies.size(); ++i) {
		if (enemies[i].isHome() == true) {
			enemies.erase(enemies.begin() + i);
			game.takeLife();
		}
	}
}

//opis stanu punktow itp
void updatePoints(Game& game, sf::Text text, sf::RenderWindow& renderWindow, std::string& w1, std::string& z1, std::string& g1, std::string& w, std::string& z, std::string& g) {
	w1 = std::to_string(game.getscore());
	z1 = std::to_string(game.getLives());
	g1 = std::to_string(game.getGold());
	text.setString(w + w1 + z + z1 + g + g1);
	renderWindow.draw(text);
}

//konczy gre
void gameEnd(Game &game, sf::Font font, sf::RenderWindow& renderWindow, int windowHeigth, int windowWidth) {
	if (game.getLives() == 0) {
		sf::Text text1;
		text1.setFont(font);
		text1.setString("Game Over");
		text1.setCharacterSize(100);
		text1.setPosition(static_cast<float>(windowHeigth / 2), static_cast<float>(windowWidth / 2));
		renderWindow.draw(text1);
		renderWindow.display();
		system("pause");
	}
}


int main() {
	//wypisywanie punktow licby zyc i dostepnych "pieniedzy"
	sf::Font font;
	if (!font.loadFromFile("res/SIXTY.ttf")) {
		std::cout << "ERROR";
	}
	int ff = 10;
	std::string w1 = std::to_string(0);
	std::string z1 = std::to_string(15);
	std::string g1 = std::to_string(0);
	sf::Text text;
	text.setFont(font);
	std::string w = "punkty: ";
	std::string z = "\t\tzycia: ";
	std::string g = "\t\tgold: ";
	text.setString(w+w1+z+z1+g+g1);
	
	//tworzenie okna
	srand(time(NULL));
	int windowWidth = 1024;
	int windowHeigth = 768;
	sf::RenderWindow renderWindow(sf::VideoMode(windowWidth, windowHeigth), "Tower Defence");
	sf::Event event;

	//tworzenie wektora wektorow strzal
	//float x1, y1;
	/*std::cout << "Podaj wspolrzedne pierwszej wiezy" << std::endl;
	std::cin >> x1 >> y1;*/
	Tower tower(100, 100);
	std::vector<Tower> arrows;
	std::vector<std::vector<Tower> > towers;
	towers.push_back(arrows);
	int towerNumber = 0;
	towers[towerNumber].push_back(tower);
	towerNumber = towerNumber + 1;

	//klasa stanu gry
	Game game(windowHeigth, windowWidth);

	//skarb
	Target treasure(static_cast<float>(windowWidth - 500), static_cast<float>(windowHeigth - 500));

	//wrowgowie
	std::vector<MovingObj> enemies1;

	//pomocnicza liczba odswiezen okna
	int abc = 1;
	Vector2i pos;
	pos.x = 100;
	pos.y = 400;
	bool isPressed = true;

	while (renderWindow.isOpen()) {

		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}			
		
		renderWindow.clear(sf::Color(0, 153, 0));

		//rysuje pierwszaw iweze
		if (abc == 1) {
			renderWindow.draw(treasure.getShape());
			sf::Text text1;
			text1.setFont(font);
			text1.setString("CREATE TOWER TO START");
			text1.setCharacterSize(50);
			text1.setPosition(static_cast<float>(windowHeigth / 2), static_cast<float>(windowWidth / 2));
			renderWindow.draw(text1);
			renderWindow.display();
			while (isPressed) {													//petla konczy sie po nacisnieciu lpm
				pos = sf::Mouse::getPosition(renderWindow);
				Tower tower1(static_cast<float>(pos.x), static_cast<float>(pos.y));
				isPressed = !(sf::Mouse::isButtonPressed(sf::Mouse::Left));
			}
			float xx = static_cast<float>(pos.x);
			float yy = static_cast<float>(pos.y);
			Vector2f pos1;
			pos1.x = xx;
			pos1.y = yy;
			towers[0][0].setTowerposition(pos1);
			towers[0][0].setPosition(pos.x, pos.y);
		}
		
		newWave(enemies1, windowWidth, windowHeigth, treasure, towerNumber);		
		
		createTower(game, arrows, renderWindow, towers, towerNumber);
		
		shoot(abc, towers, enemies1, treasure);
	
		enemiesStatus(enemies1, treasure);
		
		destroyEnemy(towers, game, enemies1);
		
		drawObjects(towers, renderWindow, treasure, enemies1, windowWidth, windowHeigth, game, font);			
		
		enemyHome(enemies1, game);
		
		updatePoints(game, text, renderWindow, w1, z1, g1, w, z, g);
		
		gameEnd(game, font, renderWindow, windowHeigth, windowWidth);
		
		abc++;
		renderWindow.display();
	}

}
