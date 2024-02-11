#include "game/game.h"
#include "game/textureHandler/textureHandler.h"
#include "SFML/Graphics.hpp"

int main() {
    Game game;

    textureAtlas textureAtlas;

    sf::Sprite sprites(textureAtlas.brickTexture);
    sprites.setOrigin(sf::Vector2f(16, 16));
    sprites.setPosition(sf::Vector2f(16, 16));

    while (game.running()) {
        game.update();

        game.render();
    }

    return 0;
}
