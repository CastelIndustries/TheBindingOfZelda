//
// Created by frangio on 24/04/18.
//

#include "Player.h"
#include <iostream>


Player::~Player() {}

void Player::Update(float deltaTime, sf::RenderWindow& window)
{
    Character::Update(deltaTime, window);
}

void Player::Draw(sf::RenderWindow& window)
{
    Character::Draw(window);
}

void Player::CorrectDisplay(sf::RenderWindow& window)
{
    Character::CorrectDisplay(window);
}



