#include "Game.h"

const int blockSize = 20;
const int width = 800;
const int height = 600;

Game::Game() {
    // Create the game window
    window.create(sf::VideoMode(width, height), "Snake Game");
    window.setFramerateLimit(10);

    // Initialize the snake, direction and food item
    snake = Snake();
    direction = Direction::Right;
    food = createFood();
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents() {
    // Keeps track of whether the direction has been changed during this frame
    static bool directionChanged = false; 

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed && !directionChanged) {
            if (event.key.code == sf::Keyboard::Up) {
                if (direction != Direction::Down) {
                    direction = Direction::Up;
                    directionChanged = true;
                }
            }
            else if (event.key.code == sf::Keyboard::Down) {
                if (direction != Direction::Up) {
                    direction = Direction::Down;
                    directionChanged = true;
                }
            }
            else if (event.key.code == sf::Keyboard::Left) {
                if (direction != Direction::Right) {
                    direction = Direction::Left;
                    directionChanged = true;
                }
            }
            else if (event.key.code == sf::Keyboard::Right) {
                if (direction != Direction::Left) {
                    direction = Direction::Right;
                    directionChanged = true;
                }
            }
        }
    }

    if (directionChanged)
        directionChanged = false;
}

void Game::update() {
    int nextX = snake.getHead().x;
    int nextY = snake.getHead().y;

    // Update the position of the snake's head based on the current direction
    switch (direction) {
    case Direction::Up:
        nextY -= 1;
        break;
    case Direction::Down:
        nextY += 1;
        break;
    case Direction::Left:
        nextX -= 1;
        break;
    case Direction::Right:
        nextX += 1;
        break;
    }

    // Check if the snake hits the edges and end the game
    if (nextX < 0 || nextX >= width / blockSize || nextY < 0 || nextY >= height / blockSize) {
        window.close();
        return;
    }

    // Update the snake's position and check for self-collision
    snake.update(nextX, nextY);

    if (snake.checkSelfCollision()) {
        window.close();
        return;
    }

    // Check if the snake ate the food
    if (nextX == food.x && nextY == food.y) {
        snake.addSegment(nextX, nextY);
        food = createFood();
    }
}

void Game::render() {
    window.clear(sf::Color::Black);

    // Draw the snake
    for (const auto& segment : snake.getSegments()) {
        sf::RectangleShape block(sf::Vector2f(blockSize - 1, blockSize - 1));
        block.setPosition(segment.x * blockSize, segment.y * blockSize);
        block.setFillColor(sf::Color::Green);
        window.draw(block);
    }

    // Draw the food
    sf::RectangleShape block(sf::Vector2f(blockSize - 1, blockSize - 1));
    block.setPosition(food.x * blockSize, food.y * blockSize);
    block.setFillColor(sf::Color::Red);
    window.draw(block);

    window.display();
}

// Generate random coordinates for the food within the game area
SnakeSegment Game::createFood() {
    int x = std::rand() % (width / blockSize);
    int y = std::rand() % (height / blockSize);
    return SnakeSegment(x, y);
}