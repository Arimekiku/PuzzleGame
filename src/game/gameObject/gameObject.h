#pragma once

#include "SFML/Graphics.hpp"
#include "gameField/gameField.h"

class GameObject {
public:
    explicit GameObject(const sf::Texture *newTexture, GameTile *newTile);

    // Update function called whenever we need, not necessarily in a game update loop
    virtual void update();

    sf::Sprite getSprite();
    GameTile *getTile();

    void setTexture(const sf::Texture& newTexture);
    void setTile(GameTile *newTile);

protected:
    GameTile *tile;
    sf::Sprite sprite;

    void updatePosition();
};