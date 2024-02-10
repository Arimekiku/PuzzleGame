#include "essentials/windowEssential/windowEssential.hpp"
#include "SFML/Graphics/Texture.hpp"

int main() {
    //TODO: remove
    sf::Texture spriteTexture;
    if (!spriteTexture.loadFromFile(R"(D:\Dev\C++\GameEngine\sprites\brick.png)")) {
        throw std::exception();
    }

    sf::Sprite test1(spriteTexture);
    sf::Sprite test2(spriteTexture);
    test2.setPosition(sf::Vector2f(400, 300));

    gameWindow gameWindow(800, 600, "Title");

    gameWindow.addEntity(test2);
    gameWindow.addEntity(test1);
    gameWindow.update();

    return 0;
}
