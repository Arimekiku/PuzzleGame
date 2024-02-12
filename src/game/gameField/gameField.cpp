#include <fstream>
#include <iostream>
#include "gameField.h"

#pragma region GameField

GameField::GameField() {
    textureAtlas = new TextureAtlas();
    objectGenerator = new Factory(textureAtlas);

    nlohmann::json map;
    std::fstream fInput;
    fInput.open(R"(D:\Dev\C++\GameEngine\resources\map\map.json)");
    fInput >> map;
    fInput.close();

    int x = 0, y = 0;

    auto mapObjects = loadMapFromJSOM(map);
    for (const auto& row : mapObjects) {
        std::vector<GameTile*> tileRow;

        for (const int& value : row) {
            auto tempObject = objectGenerator->buildGameObject(value);
            auto newTile = new GameTile(tempObject, sf::Vector2i(x, y));
            tileRow.push_back(newTile);

            x++;
        }

        tiles.push_back(tileRow);

        x = 0;
        y++;
    }

    width = tiles.size();
    height = tiles[0].size();
}

GameTile *GameField::getTile(unsigned int x, unsigned int y) {
    if (y > height || x > width) {
        std::cout << "Invalid tile search.";
        throw std::exception();
    }

    return tiles[x][y];
}

std::vector<std::vector<GameTile *>> GameField::getTiles() {
    return tiles;
}

GameField::~GameField() {
    for (auto row : tiles) {
        for (auto obj : row) {
            delete obj;
        }
    }

    delete textureAtlas;
    delete objectGenerator;
}

#pragma endregion

#pragma region GameTile

GameTile::GameTile(GameObject *newObject, sf::Vector2i newLocation) {
    tileObject = newObject;

    location = newLocation;
}

GameObject *GameTile::getContent() {
    return tileObject;
}

sf::Vector2i GameTile::getLocation() {
    return location;
}

void GameTile::setTileObject(GameObject *newObject) {
    tileObject = newObject;
}

GameTile::~GameTile() {
    delete tileObject;
}

#pragma endregion

static std::vector<std::vector<int>> loadMapFromJSOM(nlohmann::json json) {
    nlohmann::json mapJSON = json["map"];
    std::vector<std::vector<int>> map;

    std::cout << "COPY MAP FROM JSON FILE: " << std::endl;

    for (const auto& obj : mapJSON) {
        std::vector<int> row = obj;

        for (int value : row) {
            std::cout << value << " ";
        }

        map.push_back(row);

        std::cout << std::endl;
    }

    return map;
}
