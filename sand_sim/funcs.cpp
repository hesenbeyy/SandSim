#include <SFML/Graphics.hpp>
#include "macros.hpp"
#include <cstdlib>
#include <cmath>



void Sand::drawGrid(sf::RenderWindow& window) {
	for (int y = 0; y < WIDTH; y += CELL_SIZE) {
		sf::Vertex y_lines[] = {
			sf::Vertex(sf::Vector2f(y,0), sf::Color::Green),
			sf::Vertex(sf::Vector2f(y, HEIGHT), sf::Color::Green),
		};
		window.draw(y_lines, 2, sf::Lines);
	}

	for (int x = 0; x < HEIGHT; x += CELL_SIZE) {
		sf::Vertex x_lines[] = {
			sf::Vertex(sf::Vector2f(0,x), sf::Color::Green),
			sf::Vertex(sf::Vector2f(WIDTH,x), sf::Color::Green),
		};
		window.draw(x_lines, 2, sf::Lines);
	}
}

void Sand::drawSand(sf::RenderWindow& window) {
	sf::Clock clock;
	for (int y = 0; y < HEIGHT / CELL_SIZE; y++) {
		for (int x = 0; x < WIDTH / CELL_SIZE; x++) {
			if (sandData[y][x]) {
				float ratio = float(y) / (HEIGHT / CELL_SIZE); // 0 at top, 1 at bottom
				sf::Uint8 red = 255 * ratio;
				sf::Uint8 green = 200 * (1 - ratio);
				sf::Uint8 blue = 50 + 205 * sin(ratio * 3.14);

				sf::RectangleShape sand_rect(sf::Vector2f(CELL_SIZE,CELL_SIZE));
				sand_rect.setFillColor(sf::Color(red, green, blue, 255));
				sand_rect.setPosition(sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE));
				window.draw(sand_rect);
			}
		}
	}
}

void Sand::switchGeneration() {
	for (int y = HEIGHT / CELL_SIZE - 2; y >= 0; y-- ) {
		for (int x = 0; x < WIDTH / CELL_SIZE; x++) {
			if (!sandData[y][x]) continue;
			if (!sandData[y + 1][x]) {
				sandData[y + 1][x] = true;
				sandData[y][x] = false;
			}
			else {
				bool randomRightDirection = rand() % 2;
				if (x < WIDTH / CELL_SIZE - 1 && randomRightDirection && !sandData[y + 1][x + 1]) {
					sandData[y + 1][x + 1] = true;
					sandData[y][x] = false;
				}
				else if(x >= 1 && !sandData[y+1][x-1]) {
					sandData[y + 1][x - 1] = true;
					sandData[y][x] = false;
				}
			}
			
		}
	}
}

void Sand::reset() {
	for (auto& row : sandData) {
		std::fill(row.begin(), row.end(), false);
	}
}

void Sand::randomInit() {
	int ibrahim;
	for (int y = 0; y < HEIGHT / CELL_SIZE; y++) {
		for (int x = 0; x < WIDTH / CELL_SIZE; x++) {
			ibrahim = rand() % 2;
			sandData[y][x] = (ibrahim ? true : false); 
		}
	}
}