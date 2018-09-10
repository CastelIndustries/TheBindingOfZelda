//
// Created by nicola on 8/28/18.
//

#include "Skeleton.h"

Skeleton::~Skeleton() {};

void Skeleton::Create(float deltatime, sf::RenderWindow &window) {
    RangedCharacter::Create(deltatime, window);
}