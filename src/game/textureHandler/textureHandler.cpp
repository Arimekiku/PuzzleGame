#include "textureHandler.h"

TextureAtlas::TextureAtlas() {
    textures["BRICK"] = new sf::Texture();

    // Init brick texture
    if (! textures["BRICK"]->loadFromFile(BRICK_PATH)) {
        throw std::exception();
    }
}

TextureAtlas::~TextureAtlas() {
    for (const auto &texture : textures) {
        delete texture.second;
    }
}
