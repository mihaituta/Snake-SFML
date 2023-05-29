#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

struct SnakeSegment {
    int x, y;
    SnakeSegment() {}
    SnakeSegment(int x, int y) : x(x), y(y) {}
};

class Snake {
public:
    Snake();

    void addSegment(int x, int y);
    void update(int x, int y); // Update the snake's position and segments
    bool checkSelfCollision() const;
    const SnakeSegment& getHead() const;
    const std::vector<SnakeSegment>& getSegments() const; // Get all snake segments

private:
    std::vector<SnakeSegment> segments;
};

#endif 