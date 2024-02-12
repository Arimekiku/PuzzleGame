#pragma once

#include "gameObject/gameObject.h"

class Player : public GameObject {
public:
    Player(const sf::Texture* gameTexture, sf::Vector2i position = sf::Vector2i(0, 0));

    void update() override;
};