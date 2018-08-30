//
// Created by nicola on 8/30/18.
//

#include "Ghost.h"

void Ghost::CorrectDisplay(sf::RenderWindow &window) {
    MeleeCharacter::CorrectDisplay(window);
}

void Ghost::Update(float deltaTime, sf::RenderWindow &window) {
    MeleeCharacter::Update(deltaTime, window);
}

void Ghost::Draw(sf::RenderWindow &window) {
    MeleeCharacter::Draw(window);
}