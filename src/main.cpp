#include "SFML/Window.hpp"

int main() {
    int width = 800;
    int height = 600;

    sf::Vector2u windowSize(width, height);
    sf::Window window(sf::VideoMode(windowSize), "My window");

    return 0;
}
