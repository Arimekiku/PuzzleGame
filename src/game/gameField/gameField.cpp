#include <fstream>
#include "gameField.h"

#pragma region GameField

GameField::GameField() {
    nlohmann::json map;
    std::fstream fInput;
    fInput.open(R"(D:\Dev\C++\GameEngine\resources\map\map.json)");
    fInput >> map;
    fInput.close();

    int x = 0, y = 0;

    auto mapObjects = loadMapFromJSOM(map);
    for (const auto& row : mapObjects) {
        std::vector<GameTile*> tileRow;

        for (const auto& value : row) {
            auto newTile = new GameTile(value, sf::Vector2i(x, y));

            tileRow.push_back(newTile);

            x++;
        }

        tiles.push_back(tileRow);

        x = 0;
        y++;
    }

    height = tiles.size();
    width = tiles[0].size();
}

GameTile *GameField::getTile(int x, int y) {
    if (y < 0 || x < 0) {
        return nullptr;
    }

    if (y > height || x > width) {
        return nullptr;
    }

    return tiles[y][x];
}

std::vector<std::vector<GameTile *>> GameField::getTiles() {
    return tiles;
}

GameField::~GameField() {
    for (const auto& row : tiles) {
        for (auto obj : row) {
            delete obj;
        }
    }
}

#pragma endregion

#pragma region GameTile

GameTile::GameTile(TileType type, sf::Vector2i newLocation) {
    tileType = type;

    setLocation(newLocation);
}

TileType GameTile::getContent() {
    return tileType;
}

sf::Vector2i GameTile::getLocation() {
    return location;
}

void GameTile::setContent(TileType newContent) {
    tileType = newContent;
}

void GameTile::setLocation(sf::Vector2i newLocation) {
    location = newLocation;
}

#pragma endregion

static std::vector<std::vector<TileType>> loadMapFromJSOM(nlohmann::json json) {
    nlohmann::json mapJSON = json["map"];
    std::vector<std::vector<TileType>> map;

    std::cout << "COPY MAP FROM JSON FILE: " << std::endl;

    for (const auto& obj : mapJSON) {
        std::vector<int> row = obj;
        std::vector<TileType> tempTypes;

        for (int value : row) {
            std::cout << value << " ";

            switch (value) {
                case 0:
                    tempTypes.push_back(TileType::nothing);
                    break;
                case 1:
                    tempTypes.push_back(TileType::wall);
                    break;
                case 2:
                    tempTypes.push_back(TileType::player);
                    break;
                case 3:
                    tempTypes.push_back(TileType::boulder);
                    break;
                case 4:
                    tempTypes.push_back(TileType::checkpoint);
                    break;
                case 5:
                    tempTypes.push_back(TileType::trap);
                    break;
                default:
                    std::cout << "Map conversion fail" << std::endl;
                    throw std::exception();
            }
        }

        map.push_back(tempTypes);

        std::cout << std::endl;
    }

    return map;
}
