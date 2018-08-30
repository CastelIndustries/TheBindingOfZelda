//
// Created by nicola on 8/28/18.
//

#include "Skeleton.h"

Skeleton::~Skeleton() {};

void Skeleton::Draw(sf::RenderWindow &window) {
    RangedCharacter::Draw(window);
}

void Skeleton::CorrectDisplay(sf::RenderWindow &window) {
    RangedCharacter::CorrectDisplay(window);
}

void Skeleton::Update(float deltaTime, sf::RenderWindow &window) {
    RangedCharacter::CorrectDisplay(window);
}