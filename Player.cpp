//
// Created by frangio on 24/04/18.
//

#include "Player.h"
//Player::Player() {};

void Player::Update(float deltaTime, sf::RenderWindow &window) {
    RangedCharacter::Update(deltaTime, window);
};

void Player::Draw(sf::RenderWindow &window) {
    RangedCharacter::Draw(window);
};

void Player::CorrectDisplay(sf::RenderWindow &window) {
    RangedCharacter::CorrectDisplay(window);
};

Player::~Player() {};

