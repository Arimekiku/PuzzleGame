#include <iostream>
#include "gameObjectFactory.h"
#include "player/player.h"

Factory::Factory(TextureAtlas* newAtlas) {
    atlas = newAtlas;
}

GameObject* Factory::buildGameObject(GameTile* parentTile) const {
    GameObject* tempObject = nullptr;

    switch (parentTile->getContent()) {
        case TileType::nothing:
            return nullptr;
        case TileType::wall:
            tempObject = new GameObject(atlas->textures["BRICK"], parentTile);
            return tempObject;
        case TileType::player:
            tempObject = new Player(atlas->textures["PLAYER_DOWN"], parentTile);
            return tempObject;
        case TileType::boulder:
            return nullptr;
        case TileType::checkpoint:
            return nullptr;
        case TileType::trap:
            return nullptr;
        default:
            std::cout << "Can't load this type of game object." << std::endl;
            throw std::exception();
    }
}

Factory::~Factory() {
    delete atlas;
}