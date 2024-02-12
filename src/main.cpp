#include "game/game.h"

int main() {
    auto* game = new Game();

    while (game->running()) {
        game->update();

        game->render();
    }

    return 0;
}
