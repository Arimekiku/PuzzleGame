#pragma once

#include <fstream>
#include "SFML/Graphics.hpp"
#include "gameObject/gameObject.h"
#include "gameObject/gameObjectFactory.h"
#include "nlohmann/json.hpp"

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
    TextureAtlas* textureAtlas;
    Factory* gameObjectFactory;
    std::vector<GameObject*> objects;
    sf::Event e;
};

static std::vector<std::vector<int>> loadMapFromJSOM(nlohmann::json json);
