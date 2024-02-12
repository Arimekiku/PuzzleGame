#pragma once

#include "gameObject/gameObject.h"

class Player : public GameObject {
public:
    Player(const sf::Texture *gameTexture, GameTile *newTile);

    void update() override;
};