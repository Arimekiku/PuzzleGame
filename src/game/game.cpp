#include <iostream>
#include <fstream>
#include "game.h"

Game::Game() {
    window = nullptr;
    player = nullptr;
    field = nullptr;

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

                auto pPosition = player->getPosition();

                if (e.key.code == sf::Keyboard::Key::W) {
                    player->setPosition(pPosition + sf::Vector2i(0, -32));
                } else if (e.key.code == sf::Keyboard::Key::S) {
                    player->setPosition(pPosition + sf::Vector2i(0, 32));
                } else if (e.key.code == sf::Keyboard::Key::A) {
                    player->setPosition(pPosition + sf::Vector2i(-32, 0));
                } else if (e.key.code == sf::Keyboard::Key::D) {
                    player->setPosition(pPosition + sf::Vector2i(32, 0));
                }

                break;
        }
    }
}

void Game::update() {
    updateEvents();

    for (auto obj : objects) {
        obj->update();
    }
}

void Game::render() {
    window->clear();

    for (auto obj : objects) {
        window->draw(obj->getSprite());
    }

    window->draw(player->getSprite());

    window->display();
}

bool Game::running() const {
    return window->isOpen();
}

void Game::start() {
    auto vMode = sf::VideoMode(sf::Vector2u(640, 480));
    window = new sf::RenderWindow(vMode, "Title", sf::Style::Default);

    field = new GameField();
    for (const auto& row : field->getTiles()) {
        for (const auto& tile : row) {
            auto obj = tile->getContent();

            if (obj != nullptr) {
                sf::Vector2i resultPos = tile->getLocation() * 32 + sf::Vector2i(16, 16);
                obj->setPosition(resultPos);

                if (typeid(*obj) == typeid(Player)) {
                    player = dynamic_cast<Player*>(obj);
                } else {
                    addGameObject(obj);
                }
            }
        }
    }
}

void Game::addGameObject(GameObject* newObject) {
    objects.push_back(newObject);
}

Game::~Game() {
    for (auto obj : objects) {
        delete obj;
    }

    delete field;
    delete window;
}