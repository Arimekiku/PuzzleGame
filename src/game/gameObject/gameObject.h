#pragma once

#include "SFML/Graphics.hpp"

class GameObject {
public:
    explicit GameObject(const sf::Texture* gameTexture, sf::Vector2i position = sf::Vector2i(0, 0));

    void update();

    sf::Sprite getSprite();

    void setTexture(const sf::Texture& texture);

    sf::Vector2i position;

private:
    sf::Sprite sprite;
};