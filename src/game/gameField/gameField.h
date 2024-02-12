#pragma once

#include <iostream>
#include "nlohmann/json.hpp"
#include "SFML/System.hpp"

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

    void setContent(TileType newContent);
    void setLocation(sf::Vector2i newLocation);

private:
    sf::Vector2i location;

    TileType tileType;
};

class GameField {
public:
    GameField();

    GameTile* getTile(int x, int y);
    std::vector<std::vector<GameTile*>> getTiles();

    int width, height;

    ~GameField();

private:
    std::vector<std::vector<GameTile*>> tiles;
};

static std::vector<std::vector<TileType>> loadMapFromJSOM(nlohmann::json json);