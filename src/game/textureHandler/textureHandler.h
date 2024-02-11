#pragma once

#include <string>
#include "SFML/Graphics.hpp"

static const std::string BRICK_PATH = R"(D:\Dev\C++\GameEngine\resources\sprites\brick.png)";

class textureAtlas {
public:
    textureAtlas();

    sf::Texture brickTexture;
};