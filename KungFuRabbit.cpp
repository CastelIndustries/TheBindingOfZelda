//
// Created by nicola on 8/30/18.
//

#include "KungFuRabbit.h"

void KungFuRabbit::CorrectDisplay(sf::RenderWindow &window) {
    MeleeCharacter::CorrectDisplay(window);
}

void KungFuRabbit::Update(float deltaTime, sf::RenderWindow &window) {
    MeleeCharacter::Update(deltaTime, window);
}

void KungFuRabbit::Draw(sf::RenderWindow &window) {
    MeleeCharacter::Draw(window);
}

KungFuRabbit::~KungFuRabbit() {}