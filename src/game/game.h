#pragma once

#include "SFML/Graphics.hpp"
#include "gameObject/gameObject.h"
#include "gameObject/gameObjectFactory.h"
#include "player/player.h"
#include "gameField/gameField.h"

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
    sf::Event e;

    GameField* field;
    std::vector<GameObject*> objects;
    Player* player;
};