#include <SFML/Graphics.hpp>

int main()
{
    // Create the game window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Title");

    // Load font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // Handle font loading error
    }

    // Start the game loop
    sf::Clock clock;
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Calculate delta time for smooth movement
        sf::Time deltaTime = clock.restart();
    }

    return 0;
}