#pragma once

#include "SFML/Graphics.hpp"
#include "gameObject/gameObject.h"

class Game {
public:
    Game();

    void update();
    void render();
    void addGameObject(GameObject* newObject);

    [[nodiscard]] bool running() const;

    ~Game();

private:
    void start();
    void updateEvents();

    sf::RenderWindow* window;
    std::vector<GameObject*> objects;
    sf::Event e;
};
