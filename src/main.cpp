#include "game/game.h"
#include "game/textureHandler/textureHandler.h"
#include "SFML/Graphics.hpp"
#include "nlohmann/json.hpp"

int main() {
    Game game;
    textureAtlas textureAtlas;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 15; j++) {
            bool canMake = false;

            if (i == 0 || i == 19) {
                canMake = true;
            }

            if (j == 14 || j == 0) {
                canMake = true;
            }

            if (canMake) {
                auto newPosition = sf::Vector2f(16 + 32 * i, 16 + 32 * j);
                auto* tempObject = new GameObject(textureAtlas.brickTexture, newPosition);

                game.addGameObject(tempObject);
            }
        }
    }

    while (game.running()) {
        game.update();

        game.render();
    }

    return 0;
}
