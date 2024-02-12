#pragma once

#include <string>
#include <map>
#include "SFML/Graphics.hpp"

static const std::string BRICK_PATH = R"(D:\Dev\C++\GameEngine\resources\sprites\brick.png)";

class TextureAtlas {
public:
    TextureAtlas();

    std::map<std::string, sf::Texture*> textures;

    ~TextureAtlas();
};