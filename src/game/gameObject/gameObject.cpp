#include "gameObject.h"

GameObject::GameObject(const sf::Texture* gameTexture, sf::Vector2i position) :
    sprite(sf::Sprite(*gameTexture)) {
    sprite.setOrigin(sf::Vector2f(16, 16));
    setPosition(position);
}

void GameObject::update() {

}

sf::Sprite GameObject::getSprite() {
    return sprite;
}

sf::Vector2i GameObject::getPosition() {
    return position;
}

void GameObject::setTexture(const sf::Texture& newTexture) {
    sprite.setTexture(newTexture);
}

void GameObject::setPosition(const sf::Vector2i& newPosition) {
    position = newPosition;

    sprite.setPosition(sf::Vector2f(position));
}



