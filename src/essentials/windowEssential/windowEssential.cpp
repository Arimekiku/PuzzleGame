#include <iostream>
#include "windowEssential.hpp"
#include "SFML/Graphics/Texture.hpp"

gameWindow::gameWindow(int width, int height, const std::string& name) {
    windowSize = sf::Vector2u(width, height);
    windowName = name;

    open();
}

void gameWindow::open() {
    renderWindow.create(sf::VideoMode(windowSize), windowName);
    renderWindow.setVerticalSyncEnabled(true);

    isOpen = true;
}

void gameWindow::update() {
    while (isOpen) {
        sf::Event e;
        while (renderWindow.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                isOpen = false;
            }
        }

        //Draw methods
        renderWindow.clear(sf::Color::Black);

        for (const auto& sprite : sprites) {
            renderWindow.draw(sprite);
        }

        renderWindow.display();
    }
}

void gameWindow::close() {
    renderWindow.close();
}

void gameWindow::addEntity(const sf::Sprite& textureToRender) {
    sprites.push_back(textureToRender);
}

gameWindow::~gameWindow() {
    close();
}
