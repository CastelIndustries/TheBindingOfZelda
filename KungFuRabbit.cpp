//
// Created by nicola on 8/30/18.
//

#include "KungFuRabbit.h"
#include "Tile.h"

void KungFuRabbit::Create(float deltaTime, sf::RenderWindow &window) {
    if(!check)
        MeleeCharacter::Update(deltaTime, window);
    MeleeCharacter::Draw(window);
    check=false;
}


void KungFuRabbit::ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) {
    MeleeCharacter::ArtificialIntelligence(player, deltaTime, window);
}


void KungFuRabbit::Update(float deltaTime, sf::RenderWindow &window) {
    MeleeCharacter::Update(deltaTime, window);
}

void KungFuRabbit::RangedAttack() {
    MeleeCharacter::RangedAttack();
}

void KungFuRabbit::Draw(sf::RenderWindow &window) {
    MeleeCharacter::Draw(window);
}
