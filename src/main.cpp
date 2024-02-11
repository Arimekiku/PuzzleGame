#include "game/game.h"
#include "game/textureHandler/textureHandler.h"
#include "SFML/Graphics.hpp"

int main() {
    Game game;
    textureAtlas textureAtlas;

    auto* test1 = new GameObject(textureAtlas.brickTexture);
    test1->position = sf::Vector2i(320, 320);

    auto* test2 = new GameObject(textureAtlas.brickTexture);

    game.addGameObject(test1);
    game.addGameObject(test2);

    while (game.running()) {
        game.update();

        test1->update();
        test2->update();

        game.render();
    }

    return 0;
}
