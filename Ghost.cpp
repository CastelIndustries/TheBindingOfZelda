//
// Created by nicola on 8/30/18.
//

#include "Ghost.h"

Ghost::~Ghost() {};

void Ghost::Update(float deltaTime, sf::RenderWindow &window) {
    sf::Vector2f movement(0.0f, 0.0f);
    if (clock.getElapsedTime().asSeconds() > 3) {
        init = rand() % 4;
        clock.restart();
    }

    if (init == 0) {
        movement.x -= this->speed * deltaTime;
        row = 0;
    }
    if (init == 1) {
        movement.x += this->speed * deltaTime;
        row = 2;
    }
    if (init == 2) {
        movement.y -= this->speed * deltaTime;
        row = 1;
    }
    if (init == 3) {
        movement.y += this->speed * deltaTime;
        row = 3;
    }

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(movement);

}

void Ghost::Create(float deltaTime, sf::RenderWindow &window) {
    Ghost::Update(deltaTime, window);
    MeleeCharacter::Draw(window);
}
