#pragma once

#include "textureHandler/textureHandler.h"
#include "gameObject.h"

class Factory {
public:
    Factory(TextureAtlas* newAtlas);

    [[nodiscard]] GameObject* buildGameObject(int value) const;

    ~Factory();

private:
    TextureAtlas* atlas;
};