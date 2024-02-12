#include "gameObject.h"

GameObject::GameObject(const sf::Texture* gameTexture, sf::Vector2i position) :
    sprite(sf::Sprite(*gameTexture)) {

    sprite.setOrigin(sf::Vector2f(16, 16));
    sprite.setPosition(sf::Vector2f(position));
}

void GameObject::update() {
    sprite.setPosition(sf::Vector2f(position));
}

sf::Sprite GameObject::getSprite() {
    return sprite;
}

void GameObject::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);
}



