#include "game/game.h"
#include "game/textureHandler/textureHandler.h"
#include "SFML/Graphics.hpp"

int main() {
    Game game;
    textureAtlas textureAtlas;

    std::vector<GameObject*> objects;

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
                auto* tempObject = new GameObject(textureAtlas.brickTexture);
                tempObject->getSprite().setOrigin(sf::Vector2f(16, 16));
                tempObject->position = sf::Vector2i(16 + 32 * i, 16 + 32 * j);
                objects.push_back(tempObject);

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
