#include "Snake.h"

Snake::Snake() {
    // Initialize the snake with 3 segments
    segments.emplace_back(3, 3); 
    segments.emplace_back(2, 3);  
    segments.emplace_back(1, 3);  
}

// Add a new segment to the snake at the specified position
void Snake::addSegment(int x, int y) {
    segments.emplace_back(x, y);
}

void Snake::update(int x, int y) {
    // Shift the positions of segments, starting from the tail and moving towards the head
    for (int i = segments.size() - 1; i > 0; --i) {
        segments[i].x = segments[i - 1].x;
        segments[i].y = segments[i - 1].y;
    }

    // Update the position of the snake's head
    segments[0].x = x;
    segments[0].y = y;
}

bool Snake::checkSelfCollision() const {
    const SnakeSegment& head = segments[0];

    for (int i = 1; i < segments.size(); ++i)
    {
        if (head.x == segments[i].x && head.y == segments[i].y)
            return true;
    }

    return false;
}

const SnakeSegment& Snake::getHead() const {
    return segments[0];
}

const std::vector<SnakeSegment>& Snake::getSegments() const {
    return segments;
}