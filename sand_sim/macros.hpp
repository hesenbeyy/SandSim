#ifndef MACROS_H
#define MACROS_H

#include <SFML/Graphics.hpp>

#define WIDTH 800
#define HEIGHT 600
#define CELL_SIZE 10

class Sand {
public:
	std::vector<std::vector<bool>> sandData;

	Sand() : sandData((HEIGHT / CELL_SIZE), std::vector<bool>(WIDTH / CELL_SIZE, false)) {}
	void drawGrid(sf::RenderWindow& window);
	void drawSand(sf::RenderWindow& window);
	void switchGeneration();
	void randomInit();
	void reset();
};

#endif
