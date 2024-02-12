#pragma once

#include <string>
#include <map>
#include "SFML/Graphics.hpp"

static const std::string BRICK_PATH = R"(D:\Dev\C++\GameEngine\resources\sprites\brick.png)";
static const std::string PLAYER_DOWN_PATH = R"(D:\Dev\C++\GameEngine\resources\sprites\hero_down.png)";

class TextureAtlas {
public:
    TextureAtlas();

    std::map<std::string, sf::Texture*> textures;

    ~TextureAtlas();

private:
    void initTexture(const std::string& path, const std::string& name);
};