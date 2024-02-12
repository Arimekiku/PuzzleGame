#include <iostream>
#include <fstream>
#include "game.h"

Game::Game() {
    window = nullptr;
    textureAtlas = nullptr;
    gameObjectFactory = nullptr;

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

    for (auto obj : objects) {
        obj->update();
    }
}

void Game::render() {
    window->clear();

    for (auto obj : objects) {
        window->draw(obj->getSprite());
    }

    window->display();
}

bool Game::running() const {
    return window->isOpen();
}

void Game::start() {
    // SETUP STUFF
    auto vMode = sf::VideoMode(sf::Vector2u(640, 480));
    window = new sf::RenderWindow(vMode, "Title", sf::Style::Default);

    textureAtlas = new TextureAtlas();
    gameObjectFactory = new Factory(textureAtlas);

    // LOAD LEVEL
    nlohmann::json map;
    std::fstream fInput;
    fInput.open(R"(D:\Dev\C++\GameEngine\resources\map\map.json)");
    fInput >> map;
    fInput.close();

    int i = 0, j = 0;

    auto mapObjects = loadMapFromJSOM(map);
    for (const auto& row : mapObjects) {
        for (const int& value : row) {
            auto tempObject = gameObjectFactory->buildGameObject(value);

            if (tempObject != nullptr) {
                tempObject->position = sf::Vector2i(16 + 32 * i, 16 + 32 * j);

                addGameObject(tempObject);
            }

            i++;
        }

        i = 0;
        j++;
    }
}

void Game::addGameObject(GameObject* newObject) {
    objects.push_back(newObject);
}

Game::~Game() {
    for (auto obj : objects) {
        delete obj;
    }

    delete textureAtlas;
    delete gameObjectFactory;

    delete window;
}

static std::vector<std::vector<int>> loadMapFromJSOM(nlohmann::json json) {
    nlohmann::json mapJSON = json["map"];
    std::vector<std::vector<int>> map;

    std::cout << "COPY MAP FROM JSON FILE: " << std::endl;

    for (const auto& obj : mapJSON) {
        std::vector<int> row = obj;

        for (int value : row) {
            std::cout << value << " ";
        }

        map.push_back(row);

        std::cout << std::endl;
    }

    return map;
}