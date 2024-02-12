#pragma once

#include <iostream>
#include "gameObject/gameObject.h"
#include "nlohmann/json.hpp"

enum class TileType {
    nothing = 0,
    wall = 1,
    player = 2,
    boulder = 3,
    checkpoint = 4,
    trap = 5
};

class GameTile {
public:
    GameTile(TileType type, sf::Vector2i newLocation);

    TileType getContent();
    sf::Vector2i getLocation();

private:
    sf::Vector2i location;

    TileType tileType;
};

class GameField {
public:
    GameField();

    GameTile* getTile(unsigned int x, unsigned int y);
    std::vector<std::vector<GameTile*>> getTiles();
    void swapTiles(GameTile *first, GameTile *second);

    int width, height;

    ~GameField();

private:
    std::vector<std::vector<GameTile*>> tiles;
};

static std::vector<std::vector<TileType>> loadMapFromJSOM(nlohmann::json json);