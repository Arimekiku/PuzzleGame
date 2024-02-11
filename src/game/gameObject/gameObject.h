#pragma once

#include "SFML/Graphics.hpp"

class GameObject {
public:
    GameObject(const sf::Texture& gameTexture, sf::Vector2f position = sf::Vector2f(0, 0));

    void update();

    sf::Sprite getSprite();

    ~GameObject();

    sf::Vector2i position;

private:
    sf::Sprite* sprite;
};