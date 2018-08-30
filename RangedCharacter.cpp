//
// Created by nicola on 8/30/18.
//

#include "RangedCharacter.h"

void RangedCharacter::CorrectDisplay(sf::RenderWindow &window) {
    Character::CorrectDisplay(window);
}

void RangedCharacter::Update(float deltaTime, sf::RenderWindow &window) {
    Character::Update(deltaTime, window);
}

void RangedCharacter::Draw(sf::RenderWindow &window) {
    Character::Draw(window);
}