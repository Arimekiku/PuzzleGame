#include <iostream>
#include <fstream>
#include "game.h"

#pragma region Game

Game::Game() {
    window = nullptr;
    player = nullptr;
    field = nullptr;
    textureAtlas = nullptr;
    objectFactory = nullptr;

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

//                auto pPosition = player->getLocation();
//
//                if (e.key.code == sf::Keyboard::Key::W) {
//                    pPosition += sf::Vector2i(0, -1);
//                } else if (e.key.code == sf::Keyboard::Key::S) {
//                    pPosition += sf::Vector2i(0, 1);
//                } else if (e.key.code == sf::Keyboard::Key::A) {
//                    pPosition += sf::Vector2i(-1, 0);
//                } else if (e.key.code == sf::Keyboard::Key::D) {
//                    pPosition += sf::Vector2i(1, 0);
//                }

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
    // Init window
    auto vMode = sf::VideoMode(sf::Vector2u(640, 480));
    window = new sf::RenderWindow(vMode, "Title", sf::Style::Default);

    // Init services
    textureAtlas = new TextureAtlas();
    objectFactory = new Factory(textureAtlas);

    // Init objects
    field = new GameField();
    for (const auto& row : field->getTiles()) {
        for (const auto& tile : row) {
            GameObject *objectToBuild = objectFactory->buildGameObject(tile->getContent());

            if (objectToBuild != nullptr) {
                sf::Vector2i resultPos = tile->getLocation() * 32 + sf::Vector2i(16, 16);
                objectToBuild->setPosition(resultPos);

                if (typeid(*objectToBuild) == typeid(Player)) {
                    player = dynamic_cast<Player *>(objectToBuild);
                } else {
                    addGameTile(objectToBuild);
                }
            }
        }
    }
}

void Game::addGameTile(GameObject* newObject) {
    objects.push_back(newObject);
}

Game::~Game() {
    for (auto obj : objects) {
        delete obj;
    }

    delete field;
    delete objectFactory;
    delete textureAtlas;
    delete window;
}

#pragma endregion

