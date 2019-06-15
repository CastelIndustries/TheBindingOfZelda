//
// Created by nicola on 10/06/19.
//

#include "MeleeStrategy.h"
#include "DEFINITIONS.h"
#include <cmath>


void MeleeStrategy::Attack(Character *player, Character &character, float deltaTime, sf::RenderWindow &window) {
    character.distance = sqrt(pow(character.body.getPosition().x - player->body.getPosition().x, 2) +
                              pow(character.body.getPosition().y - player->body.getPosition().y, 2));

    if (character.distance < RANGE) {
        character.ArtificialIntelligence(*player, deltaTime, window);
    }
    if (character.body.getGlobalBounds().intersects(player->body.getGlobalBounds())) {
        if (character.PunchClock.getElapsedTime() >= character.ShootDelay) {
            character.punching = true;
            character.PunchClock.restart();
        }
    }

}