//
// Created by nicola on 8/30/18.
//

#include "Ghost.h"

Ghost::~Ghost() {};


void Ghost::Create(float deltaTime, sf::RenderWindow &window) {
    if(!check)
        MeleeCharacter::Update(deltaTime, window);
    MeleeCharacter::Draw(window);
    check=false;
}

void Ghost::ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) {
    MeleeCharacter::ArtificialIntelligence(player, deltaTime, window);
}

void Ghost::Draw(sf::RenderWindow &window) {
    MeleeCharacter::Draw(window);
}

void Ghost::Update(float deltaTime, sf::RenderWindow &window) {
    MeleeCharacter::Update(deltaTime, window);
}

void Ghost::RangedAttack() {
    MeleeCharacter::RangedAttack();
}
