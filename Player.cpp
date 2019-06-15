//
// Created by frangio on 24/04/18.
//

#include "Player.h"
#include "TileMap.h"
#include "HUD.h"
#include "DEFINITIONS.h"

Player::~Player() {};

void Player::Update(float deltaTime, sf::RenderWindow &window) {
    //sf::Vector2f movement(0.0f, 0.0f);

    bool stop=false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        body.move(-this->speed, 0);
        this->row = 2;
    }
    if (sf::Keyboard::isKeyPressed(
            sf::Keyboard::D)) {
        body.move(this->speed, 0);
        this->row = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        body.move(0, -this->speed);
        this->row = 1;
    }
    if (sf::Keyboard::isKeyPressed(
            sf::Keyboard::S)) {
        body.move(0,this->speed);
        this->row = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        this->speed = this->dash +4;
    else
        this->speed = this->dash;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        row=4;
        punching = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        row=5;
        punching = true;
    }


    if (stop) {
        this->animation.StopUpdate(this->row);
    } else
        this->animation.Update(this->row, deltaTime);

    this->body.setTextureRect(this->animation.uvRect);
//this->body.move(movement);
}


void Player::Create(float deltaTime, sf::RenderWindow &window) {
    Player::Update(deltaTime, window);
    RangedCharacter::Draw(window);
}

void Player::RangedAttack() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && BulletClock.getElapsedTime()>=ShootDelay){
        this->playerDir=sf::Vector2f(-1, 0);
        isFiring= true;
        BulletClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(
            sf::Keyboard::Up) && BulletClock.getElapsedTime()>=ShootDelay) {
        this->playerDir=sf::Vector2f(0, -1);
        isFiring= true;
        BulletClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && BulletClock.getElapsedTime()>=ShootDelay) {
        this->playerDir=sf::Vector2f(1, 0);
        isFiring= true;
        BulletClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(
            sf::Keyboard::Down) && BulletClock.getElapsedTime()>=ShootDelay) {
        this->playerDir=sf::Vector2f(0 ,1);
        isFiring= true;
        BulletClock.restart();
    }

}

void Player::RegisterObserver(Observer *observer) {
    observers.push_back(observer);
}

void Player::RemoveObserver(Observer *observer) {
    observers.remove(observer);
}

void Player::NotifyObservers(GameDataRef &_data, TileMap &map, sf::RenderWindow &window, HUD &hud) {

    l_kills = _data->totalKills;
    best = _data->totalKills == _data->highScore + 1;



    if (kills == _data->numEnemies) {
        roomCompletedText = true;
        for (auto itr:observers) {
            itr->update(map, window);
            kills = 0;
        }




    }
    if(doorNewLevel) {
        for (auto itr:observers) {
            itr->newLevel(_data);
        }
        body.setPosition(defaultPos);
        doorNewLevel = false;
        roomCompletedText = false;
    }



    if(best) {
        for (auto itr : observers)
            itr->newHighScore(_data, hud);
        best=false;
    }
}

void Player::Draw(sf::RenderWindow &window) {
    RangedCharacter::Draw(window);
}

void Player::ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) {

}





