#include "game.h"

Game::Game() {
    window = nullptr;

    start();
}

void Game::updateEvents() {
    while(window->pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (e.key.code == sf::Keyboard::Key::Escape) {
                    window->close();
                }
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    updateEvents();
}

void Game::render() {
    window->clear();

    window->display();
}

bool Game::running() const {
    return window->isOpen();
}

void Game::start() {
    auto vMode = sf::VideoMode(sf::Vector2u(640, 480));
    window = new sf::RenderWindow(vMode, "Title", sf::Style::Default);
}

Game::~Game() {
    delete window;
}
