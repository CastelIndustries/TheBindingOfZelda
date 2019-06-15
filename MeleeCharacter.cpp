//// Created by nicola on 8/30/18.
//

#include "MeleeCharacter.h"
#include "DEFINITIONS.h"


void MeleeCharacter::Create(float deltaTime, sf::RenderWindow &window) {
    Character::Create(deltaTime, window);
}

void MeleeCharacter::Update(float deltaTime, sf::RenderWindow &window) {

    bool stop = false;

    if (clock.getElapsedTime().asSeconds() > 3) {
        init = rand() % 4;
        clock.restart();
    }

    if (init == 0) {
        body.move(-this->speed, 0);
        if(!check)
            row = 0;
    }
    if (init == 1) {
        body.move(this->speed, 0);
        if(!check)
            row = 2;
    }
    if (init == 2) {
        body.move(0 , -this->speed);
        if(!check)
            row = 1;
    }
    if (init == 3) {
        body.move(0, this->speed);
        if (!check)
            row = 3;
    }



    if (stop) {
        this->animation.StopUpdate(this->row);
    } else
        this->animation.Update(this->row, deltaTime);

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
}


void MeleeCharacter::ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) {

    playerDir.x = (player.body.getPosition().x - body.getPosition().x)/distance;
    playerDir.y = (player.body.getPosition().y - body.getPosition().y)/distance;

    if (playerDir.x > 0 && std::abs(playerDir.y) < std::abs(playerDir.x)){            //DESTRA

        row = 2;
    }
    if (playerDir.x < 0 && std::abs(playerDir.y) < std::abs(playerDir.x)){            //SINISTRA

        row = 0;

    }
    if (playerDir.y > 0 && std::abs(playerDir.y) > std::abs(playerDir.x)){            //GIU

        row = 3;

    }
    if (playerDir.y < 0 && std::abs(playerDir.y) > std::abs(playerDir.x)){            //SU

        row = 1;

    }

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(playerDir.x * this->speed, playerDir.y * this->speed);


    check= true;

}


void MeleeCharacter::RangedAttack() {

}

void MeleeCharacter::Draw(sf::RenderWindow &window) {
    Character::Draw(window);
}
