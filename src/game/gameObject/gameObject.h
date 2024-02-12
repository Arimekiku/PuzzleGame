#pragma once

#include "SFML/Graphics.hpp"

class GameObject {
public:
    explicit GameObject(const sf::Texture* gameTexture, sf::Vector2i position = sf::Vector2i(0, 0));

    virtual void update();

    sf::Sprite getSprite();
    sf::Vector2i getPosition();

    void setTexture(const sf::Texture& newTexture);
    void setPosition(const sf::Vector2i& newPosition);

protected:
    sf::Vector2i position;
    sf::Sprite sprite;
};