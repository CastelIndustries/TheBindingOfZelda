//
// Created by nicola on 8/30/18.
//

#include "MeleeCharacter.h"

void MeleeCharacter::CorrectDisplay(sf::RenderWindow &window) {
    Character::CorrectDisplay(window);
}

void MeleeCharacter::Update(float deltaTime, sf::RenderWindow &window) {
    Character::Update(deltaTime, window);
}

void MeleeCharacter::Draw(sf::RenderWindow &window) {
    Character::Draw(window);
}