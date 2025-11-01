#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "macros.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sand Simulation");
	
	srand(time(NULL));
	bool isLeftDragged = false;
	bool isRightDragged = false;

	sf::Vector2i mousePos;
	Sand sand_sim;

	//sf::RectangleShape rect(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	//sf::Clock clock;
	const float frameDelay = 0.02f;
	sand_sim.randomInit();


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				isLeftDragged = true;
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
				isRightDragged = true;
			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right) {
				isRightDragged = false;
			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
				isLeftDragged = false;
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) window.close();
				if (event.key.code == sf::Keyboard::R) {
					sand_sim.reset();
				}
			}
		}

		/*if (clock.getElapsedTime().asSeconds() >= frameDelay) {
			sand_sim.switchGeneration();
			clock.restart();
		}*/

		
		if (isLeftDragged || isRightDragged) {
			mousePos = sf::Vector2i(sf::Mouse::getPosition(window));
			int grid_x = mousePos.x / CELL_SIZE;
			int grid_y = mousePos.y / CELL_SIZE;
			if (grid_x >= 0 && grid_x < WIDTH / CELL_SIZE && grid_y >= 0 && grid_y < HEIGHT / CELL_SIZE) {
				if (isLeftDragged) sand_sim.sandData[grid_y][grid_x] = true;
				else if (isRightDragged) sand_sim.sandData[grid_y][grid_x] = false;
			}
		}

		window.clear();
		sand_sim.drawSand(window);
		//sand_sim.drawGrid(window);
		sand_sim.switchGeneration();
		window.display();

	}

}