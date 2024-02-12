#include "game/game.h"
#include "nlohmann/json.hpp"

int main() {
    auto* game = new Game();

    while (game->running()) {
        game->update();

        game->render();
    }

    return 0;
}
