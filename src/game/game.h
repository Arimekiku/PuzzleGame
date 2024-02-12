#pragma once

#include "SFML/Graphics.hpp"
#include "gameObject/gameObject.h"
#include "gameObject/gameObjectFactory.h"
#include "nlohmann/json.hpp"
#include "player/player.h"

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

    TextureAtlas* textureAtlas;
    Factory* gameObjectFactory;

    sf::RenderWindow* window;
    sf::Event e;

    std::vector<GameObject*> objects;
    Player* player;
};

static std::vector<std::vector<int>> loadMapFromJSOM(nlohmann::json json);
