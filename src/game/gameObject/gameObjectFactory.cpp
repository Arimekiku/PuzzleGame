#include <iostream>
#include "gameObjectFactory.h"

Factory::Factory(TextureAtlas* newAtlas) {
    atlas = newAtlas;
}

GameObject *Factory::buildGameObject(int value) const {
    switch (GameObject* newObject = nullptr; value) {
        case 0:
            return nullptr;
        case 1:
            newObject = new GameObject(atlas->textures["BRICK"]);
            return newObject;
        default:
            std::cout << "Can't load this type of game object." << std::endl;
            throw std::exception();
    }
}

Factory::~Factory() {
    delete atlas;
}