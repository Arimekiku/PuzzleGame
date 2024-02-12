#include <iostream>
#include "gameObjectFactory.h"
#include "player/player.h"

Factory::Factory(TextureAtlas* newAtlas) {
    atlas = newAtlas;
}

GameObject* Factory::buildGameObject(int value) const {
    GameObject* tempObject = nullptr;
    switch (value) {
        case 0:
            return nullptr;
        case 1:
            tempObject = new GameObject(atlas->textures["BRICK"]);
            return tempObject;
        case 2:
            tempObject = new Player(atlas->textures["PLAYER_DOWN"]);
            return tempObject;
        default:
            std::cout << "Can't load this type of game object." << std::endl;
            throw std::exception();
    }
}

Factory::~Factory() {
    delete atlas;
}