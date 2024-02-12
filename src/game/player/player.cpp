#include "player.h"

Player::Player(const sf::Texture *gameTexture, GameTile *newTile) : GameObject(gameTexture, newTile) {

}

void Player::update() {
    GameObject::update();

    std::cout << "New Position: " << tile->getLocation().x << " " << tile->getLocation().y;

    // TODO: make things work
}
