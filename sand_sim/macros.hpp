// Crucial steps:

// 1 - draw a rectangle, in random position
// 2 - learn mouse drag and getting position, and according to that draw rectangles
// 3 - use 2d array to store data
// 4 - if down part of sand is 0, make it 1 and make current 0. always start from bottom ig

// Notes:

// 28/10/25 update, seems like i gotta implement the array first, then ill keep the data. according to that data ill draw rectangles
// js learnt that i cant initialize a dynamic memory type inside class, i can declare it but initializing should be in the constructor

// 29/10/25 finished implementation, just add some things for decoration


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