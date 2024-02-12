#pragma once

#include "textureHandler/textureHandler.h"
#include "gameObject.h"
#include "gameField/gameField.h"

class Factory {
public:
    explicit Factory(TextureAtlas* newAtlas);

    [[nodiscard]] GameObject* buildGameObject(TileType type) const;

    ~Factory();

private:
    TextureAtlas* atlas;
};