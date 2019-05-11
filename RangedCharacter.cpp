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
    if (body.getPosition().x <= player.body.getPosition().x + player.body.getSize().x + range &&
        body.getPosition().y + (body.getSize().y) / 2 <= player.body.getPosition().y + (player.body.getSize().y) &&
        body.getPosition().y + (body.getSize().y) / 2 >= player.body.getPosition().y && BulletClock.getElapsedTime() >=
                                                                                        ShootDelay /*&& body.getPosition().x + body.getLocalBounds().width <= window.getSize().x*/) {

        isFiring = true;
        dirRanAtt = 2;
        BulletClock.restart();
        row = 3;
        //body.move(speed*2 * deltaTime,0.f);
        movement.x += this->speed * deltaTime;
        this->animation.Update(this->row, deltaTime);

        animation.Update(row, deltaTime);
        body.setTextureRect(animation.uvRect);
        body.move(movement);
    } else if (body.getPosition().x + body.getSize().x + range >= player.body.getPosition().x &&
               body.getPosition().y + (body.getSize().y) / 2 <= player.body.getPosition().y + player.body.getSize().y &&
               body.getPosition().y + (body.getSize().y) / 2 >= player.body.getPosition().y &&
               BulletClock.getElapsedTime() >= ShootDelay /*&& body.getPosition().x >= this->speed * deltaTime*/) {

        isFiring = true;
        dirRanAtt = 0;
        BulletClock.restart();
        row = 2;
        //body.move(-speed*2 * deltaTime,0.f);
        movement.x -= this->speed * deltaTime;
        this->animation.Update(this->row, deltaTime);

        animation.Update(row, deltaTime);
        body.setTextureRect(animation.uvRect);
        body.move(movement);
    } else if (body.getPosition().y <= player.body.getPosition().y + player.body.getSize().y + range &&
               body.getPosition().x + body.getSize().x / 2 <= player.body.getPosition().x + player.body.getSize().x &&
               body.getPosition().x + (body.getSize().x) / 2 >= player.body.getPosition().x &&
               BulletClock.getElapsedTime() >=
               ShootDelay  /*&& body.getPosition().y + body.getLocalBounds().width <= window.getSize().y - 60 */) {

        isFiring = true;
        dirRanAtt = 3;
        BulletClock.restart();
        row = 0;
        //body.move(0.0f,speed*2 * deltaTime);
        movement.y += this->speed * deltaTime;
        this->animation.Update(this->row, deltaTime);

        animation.Update(row, deltaTime);
        body.setTextureRect(animation.uvRect);
        body.move(movement);
    } else if (body.getPosition().y <= player.body.getPosition().y + player.body.getSize().y + range &&
               body.getPosition().x + (body.getSize().x) / 2 <= player.body.getPosition().x + player.body.getSize().x &&
               body.getPosition().x + (body.getSize().x) / 2 >= player.body.getPosition().x &&
               BulletClock.getElapsedTime() >= ShootDelay /*&& body.getPosition().y >= -40*/) {

        isFiring = true;
        dirRanAtt = 1;
        BulletClock.restart();
        row = 1;
        //body.move(0.0f,-speed*2 * deltaTime);
        movement.y -= this->speed * deltaTime;
        this->animation.Update(this->row, deltaTime);

        animation.Update(row, deltaTime);
        body.setTextureRect(animation.uvRect);
        body.move(movement);
    } else {
        this->Update(deltaTime, window);
    }


}



