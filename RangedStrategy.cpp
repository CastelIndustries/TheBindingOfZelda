//
// Created by nicola on 10/06/19.
//

#include <tgmath.h>
#include "RangedStrategy.h"
#include "Character.h"

void RangedStrategy::Attack(Character *player, Character &character, float deltaTime, sf::RenderWindow &window) {
    character.distance = sqrt(pow(character.body.getPosition().x - player->body.getPosition().x, 2) +
                              pow(character.body.getPosition().y - player->body.getPosition().y, 2));

    if (character.distance < RANGE) {
        character.ArtificialIntelligence(*player, deltaTime, window);
        if (character.BulletClock.getElapsedTime() >= character.ShootDelay) {
            character.isFiring = true;
            character.BulletClock.restart();
        }
    }
}

RangedStrategy::RangedStrategy() : Strategy() {

}

