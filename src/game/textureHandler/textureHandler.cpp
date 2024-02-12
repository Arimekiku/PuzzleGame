#include "textureHandler.h"

TextureAtlas::TextureAtlas() {
    initTexture(BRICK_PATH, "BRICK");
    initTexture(PLAYER_DOWN_PATH, "PLAYER_DOWN");
}

void TextureAtlas::initTexture(const std::string& path, const std::string& name) {
    textures[name] = new sf::Texture();
    if (!textures[name]->loadFromFile(path)) {
        throw std::exception();
    }
}

TextureAtlas::~TextureAtlas() {
    for (const auto &texture : textures) {
        delete texture.second;
    }
}
