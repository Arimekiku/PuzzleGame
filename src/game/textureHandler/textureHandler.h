#pragma once

#include <string>
#include "SFML/Graphics.hpp"

static const std::string BRICK_PATH = "sprites/brick.png";

enum Textures {
    brickTexture,
};

class textureAtlas {
public:
    textureAtlas();

    sf::Texture brickTexture;
};