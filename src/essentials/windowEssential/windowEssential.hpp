#include "SFML/Window.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"

class gameWindow {
public:
    gameWindow(int width, int height, const std::string& name);

    void update();
    void addEntity(const sf::Sprite& textureToRender);

    ~gameWindow();
private:
    void open();
    void close();

    bool isOpen = false;
    sf::Vector2u windowSize;
    std::string windowName;
    sf::RenderWindow renderWindow;
    std::vector<sf::Sprite> sprites;
};
