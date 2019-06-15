//
// Created by nicola on 8/30/18.
//

#include "RangedCharacter.h"
#include <cmath>
#include <stdlib.h>
#include "DEFINITIONS.h"


void RangedCharacter::Update(float deltaTime, sf::RenderWindow &window) {
    bool stop = false;

    if (clock.getElapsedTime().asSeconds() > 2) {
        init = rand() % 4;
        clock.restart();
    }

    if (init == 0) {
        body.move(-this->speed, 0);
        if(!check)
            row = 2;
    }
    if (init == 1) {
        body.move(this->speed, 0);
        if(!check)
            row = 3;
    }
    if (init == 2) {
        body.move(0 , -this->speed);
        if(!check)
            row = 1;
    }
    if (init == 3) {
        body.move(0, this->speed);
        if (!check)
            row = 0;
    }



    if (stop) {
        this->animation.StopUpdate(this->row);
    } else
        this->animation.Update(this->row, deltaTime);

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);


}

void RangedCharacter::Create(float deltaTime, sf::RenderWindow &window) {
    Character::Create(deltaTime, window);
}
void RangedCharacter::RangedAttack() {
    if(BulletClock.getElapsedTime() >= ShootDelay) {
        std::cout<<"FIRE" << std::endl;
        isFiring = true;
        BulletClock.restart();
    }
}

void RangedCharacter::ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) {

    playerDir.x = (player.body.getPosition().x - body.getPosition().x)/distance;
    playerDir.y = (player.body.getPosition().y - body.getPosition().y)/distance;

    if (playerDir.x > 0 && std::abs(playerDir.y) < std::abs(playerDir.x)){            //DESTRA

        row = 3;
    }
    if (playerDir.x < 0 && std::abs(playerDir.y) < std::abs(playerDir.x)){            //SINISTRA

        row = 2;

    }
    if (playerDir.y > 0 && std::abs(playerDir.y) > std::abs(playerDir.x)){            //GIU

        row = 0;

    }
    if (playerDir.y < 0 && std::abs(playerDir.y) > std::abs(playerDir.x)){            //SU

        row = 1;

    }

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(playerDir.x * this->speed, playerDir.y * this->speed);

    if(distance<RANGE-300)
        RangedAttack();

    check= true;

}

void RangedCharacter::Draw(sf::RenderWindow &window) {
    Character::Draw(window);
}



