#include "gameObject.h"

GameObject::GameObject(const sf::Texture& gameTexture, sf::Vector2f position) {
    sprite = new sf::Sprite(gameTexture);
    sprite->setOrigin(sf::Vector2f(16, 16));
    sprite->setPosition(position);
}

void GameObject::update() {
    sprite->setPosition(sf::Vector2f(position));
}

sf::Sprite GameObject::getSprite() {
    return *sprite;
}

GameObject::~GameObject() {
    delete sprite;
}



