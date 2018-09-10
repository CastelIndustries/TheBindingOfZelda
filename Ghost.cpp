//
// Created by nicola on 8/30/18.
//

#include "Ghost.h"

void Ghost::Create(float deltatime, sf::RenderWindow &window) {
    MeleeCharacter::Create(deltatime, window);
}
Ghost::~Ghost() {}