#pragma once

#include <vector>
#include "gameObject/gameObject.h"
#include "gameObject/gameObjectFactory.h"
#include "nlohmann/json.hpp"

enum GameTiles {
    NOTHING = 0,
    WALL = 1,
    PLAYER = 2,
    BOULDER = 3,
    CHECKPOINT = 4,
    TRAP = 5
};

class GameTile {
public:
    GameTile(GameObject* newObject, sf::Vector2i newLocation);

    GameObject* getContent();
    sf::Vector2i getLocation();

    void setTileObject(GameObject* newObject);

    ~GameTile();

private:
    sf::Vector2i location;

    GameObject* tileObject;
};

class GameField {
public:
    GameField();

    GameTile* getTile(unsigned int x, unsigned int y);
    std::vector<std::vector<GameTile*>> getTiles();

    int width, height;

    ~GameField();

private:
    std::vector<std::vector<GameTile*>> tiles;

    TextureAtlas* textureAtlas;
    Factory* objectGenerator;
};

static std::vector<std::vector<int>> loadMapFromJSOM(nlohmann::json json);