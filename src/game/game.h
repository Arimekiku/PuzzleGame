#pragma once

#include "SFML/Graphics.hpp"

class Game {
public:
    Game();

    void update();
    void render();

    [[nodiscard]] bool running() const;

    ~Game();

private:
    void start();
    void updateEvents();

    sf::RenderWindow* window;
    sf::Event e;
};
