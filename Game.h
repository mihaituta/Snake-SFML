#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Snake.h"

enum class Direction {
    Up,
    Down,
    Left,
    Right
};

class Game {
public:
    Game();
    void run(); // Run the game loop

private:
    void handleEvents(); // Handle user input events
    void update();
    void render();  // Render the game graphics
    SnakeSegment createFood(); // Create a new food item

    sf::RenderWindow window;
    Snake snake;
    Direction direction;
    SnakeSegment food;
};

#endif