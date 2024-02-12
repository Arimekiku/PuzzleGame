#include "gameObject.h"

GameObject::GameObject(const sf::Texture *newTexture, GameTile *newTile) :
    sprite(sf::Sprite(*newTexture)),
    tile(newTile) {
        sprite.setOrigin(sf::Vector2f(16, 16));

        updatePosition();
}

void GameObject::update() {
    updatePosition();
}

sf::Sprite GameObject::getSprite() {
    return sprite;
}

GameTile *GameObject::getTile() {
    return tile;
}

void GameObject::setTexture(const sf::Texture& newTexture) {
    sprite.setTexture(newTexture);
}

void GameObject::setTile(GameTile *newTile) {
    tile = newTile;

    updatePosition();
}

void GameObject::updatePosition() {
    sf::Vector2f newPosition = sf::Vector2f(tile->getLocation() * 32 + sf::Vector2i(16, 16));
    sprite.setPosition(newPosition);
}