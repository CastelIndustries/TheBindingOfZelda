//
// Created by nicola on 8/28/18.
//

#include "Skeleton.h"
#include "DEFINITIONS.h"

Skeleton::~Skeleton() {};


void Skeleton::Create(float deltaTime, sf::RenderWindow &window) {
    if(!check)
        RangedCharacter::Update(deltaTime, window);
    RangedCharacter::Draw(window);
    check=false;
}

void Skeleton::Update(float deltatime, sf::RenderWindow &window) {
    RangedCharacter::Update(deltatime, window);
}

void Skeleton::Draw(sf::RenderWindow &window) {
    RangedCharacter::Draw(window);
}

void Skeleton::ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) {
    RangedCharacter::ArtificialIntelligence(player, deltaTime, window);
}


