//
// Created by frangio on 24/04/18.
//

#include "Player.h"
#include "Collider.h"
#include <list>
#include "iostream"
#include "TileMap.h"

Player::~Player() {};

void Player::Update(float deltaTime, sf::RenderWindow &window) {
    sf::Vector2f movement(0.0f, 0.0f);

        bool stop=false;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){// && body.getPosition().x >= 0) {
            movement.x -= this->speed * deltaTime;
            row = 2;
        }else {
            if (sf::Keyboard::isKeyPressed(
                    sf::Keyboard::D)) {// && body.getPosition().x + body.getLocalBounds().width <= window.getSize().x) {
                movement.x += this->speed * deltaTime;
                this->row = 3;
            } else {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {// && body.getPosition().y >=-40) {
                    movement.y -= this->speed * deltaTime;
                    this->row = 1;
                } else {
                    if (sf::Keyboard::isKeyPressed(
                            sf::Keyboard::S)) {// && body.getPosition().y+ body.getLocalBounds().width <= window.getSize().y-60) {
                        movement.y += this->speed * deltaTime;
                        this->row = 0;
                    } else {
                        stop = true;

                    }
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            this->speed = this->dash * 2;
        else
            this->speed = this->dash;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        //row=4;
        punching = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        //row=5;
        punching = true;
    }


    if (stop) {
            this->animation.StopUpdate(this->row);
        } else
            this->animation.Update(this->row, deltaTime);

        this->body.setTextureRect(this->animation.uvRect);
        this->body.move(movement);
}


void Player::Create(float deltaTime, sf::RenderWindow &window) {
    Player::Update(deltaTime, window);
    RangedCharacter::Draw(window);
}

void Player::RangedAttack() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && BulletClock.getElapsedTime()>=ShootDelay){

         dirRanAtt=0;
        isFiring= true;
        BulletClock.restart();

    }else {
        if (sf::Keyboard::isKeyPressed(
                sf::Keyboard::Up) && BulletClock.getElapsedTime()>=ShootDelay) {
            dirRanAtt=1;
            isFiring= true;
            BulletClock.restart();
        } else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && BulletClock.getElapsedTime()>=ShootDelay) {
                dirRanAtt=2;
                isFiring= true;
                BulletClock.restart();
            } else {
                if (sf::Keyboard::isKeyPressed(
                        sf::Keyboard::Down) && BulletClock.getElapsedTime()>=ShootDelay) {
                    dirRanAtt=3;
                    isFiring= true;
                    BulletClock.restart();
                }
            }
        }
    }

}

void Player::RegisterObserver(Observer *observer) {
    observers.push_back(observer);
}

void Player::RemoveObserver(Observer *observer) {
    observers.remove(observer);
}

void Player::NotifyObservers(TileMap &map, sf::RenderWindow &window) {

    if (kills == 3) {
        roomCompletedText = true;
        for (auto itr:observers) {
            itr->update(map, window);
            kills = 0;
        }

    }
    if(doorNewLevel) {
        for (auto itr:observers) {
            itr->newLevel(map, window);
            NewLevel = true;
            body.setPosition(defaultPos);
            doorNewLevel = false;
            roomCompletedText = false;
            l_kills=0;
        }

    }



}

void Player::Punch(Character &character) {
    if (punching && character.GetCollider().CheckCollision(this->GetCollider(), 0.0f)) {
        character.hp--;
    }
}





