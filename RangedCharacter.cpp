//
// Created by nicola on 8/30/18.
//

#include "RangedCharacter.h"


void RangedCharacter::Update(float deltaTime, sf::RenderWindow &window) {
    bool stop = false;


    sf::Vector2f movement(0.0f, 0.0f);
    if (clock.getElapsedTime().asSeconds() > 3) {
        init = rand() % 4;
        clock.restart();
    }

    if (init == 0) {
        movement.x -= this->speed * deltaTime;

        row = 2;
    }
    if (init == 1) {
        movement.x += this->speed * deltaTime;
        row = 3;
    }
    if (init == 2) {
        movement.y -= this->speed * deltaTime;
        row = 1;
    }
    if (init == 3) {
        movement.y += this->speed * deltaTime;
        row = 0;
    }


    if (stop) {
        this->animation.StopUpdate(this->row);
    } else
        this->animation.Update(this->row, deltaTime);

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(movement);

}

void RangedCharacter::Create(float deltaTime, sf::RenderWindow &window) {
    Character::Create(deltaTime, window);
}
void RangedCharacter::RangedAttack() {
    Character::RangedAttack();
}

void RangedCharacter::ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) {


    sf::Vector2f movement(0.0f, 0.0f);
    if (body.getPosition().x + range <= player.body.getPosition().x &&
        body.getPosition().y + (body.getSize().y) / 2 <= player.body.getPosition().y + (player.body.getSize().y) &&
        body.getPosition().y + (body.getSize().y) / 2 >= player.body.getPosition().y){

        if(BulletClock.getElapsedTime() >= ShootDelay) {
            isFiring = true;
            BulletClock.restart();
        }

        dirRanAtt = 2;

        row = 3;
        movement.x += speed * deltaTime;
        Check = true;
    } else if (body.getPosition().x >= player.body.getPosition().x + range &&
               body.getPosition().y + (body.getSize().y) / 2 <= player.body.getPosition().y + player.body.getSize().y &&
               body.getPosition().y + (body.getSize().y) / 2 >= player.body.getPosition().y){


        if(BulletClock.getElapsedTime() >= ShootDelay) {
            isFiring = true;
            BulletClock.restart();
        }
        dirRanAtt = 0;
        row = 2;
        movement.x -= speed * deltaTime;
        Check = true;
    } else if (
            body.getPosition().y + body.getSize().y + range <= player.body.getPosition().y + player.body.getSize().y &&
               body.getPosition().x + body.getSize().x / 2 <= player.body.getPosition().x + player.body.getSize().x &&
               body.getPosition().x + (body.getSize().x) / 2 >= player.body.getPosition().x){

        if(BulletClock.getElapsedTime() >= ShootDelay) {
            isFiring = true;
            BulletClock.restart();
        }
        dirRanAtt = 3;
        row = 0;
        movement.y += speed * deltaTime;
        Check = true;
    } else if (body.getPosition().y >= player.body.getPosition().y + range &&
               body.getPosition().x + (body.getSize().x) / 2 <= player.body.getPosition().x + player.body.getSize().x &&
               body.getPosition().x + (body.getSize().x) / 2 >= player.body.getPosition().x){

        if(BulletClock.getElapsedTime() >= ShootDelay) {
            isFiring = true;
            BulletClock.restart();
        }
        dirRanAtt = 1;
        row = 1;
        movement.y -= speed * deltaTime;
        Check = true;
    }

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(movement);



}



