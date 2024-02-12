#pragma once

#include "textureHandler/textureHandler.h"
#include "gameObject.h"

class Factory {
public:
    explicit Factory(TextureAtlas* newAtlas);

    [[nodiscard]] GameObject* buildGameObject(int value) const;

    ~Factory();

private:
    TextureAtlas* atlas;
};