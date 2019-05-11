//
// Created by nicola on 8/28/18.
//

#include "Skeleton.h"

Skeleton::~Skeleton() {};

/*void Skeleton::Update(float deltaTime, sf::RenderWindow &window) {
    bool stop = false;

    sf::Vector2f movement(0.0f, 0.0f);
    if (clock.getElapsedTime().asSeconds() > 3) {
        init = rand() % 4;
        clock.restart();
    }

    if (init == 0){
        movement.x -= this->speed * deltaTime;

        row = 2;
    }
    if (init == 1){
        movement.x += this->speed * deltaTime;
        row = 3;
    }
    if (init == 2){
        movement.y -= this->speed * deltaTime;
        row = 1;
    }
    if (init == 3){
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


}*/

void Skeleton::Create(float deltaTime, sf::RenderWindow &window) {
    //RangedCharacter::Update(deltaTime, window);
    RangedCharacter::Draw(window);
}

void Skeleton::RegisterObserver(Observer *observer) {
    observers.push_back(observer);
}

void Skeleton::RemoveObserver(Observer *observer) {
    observers.remove(observer);
}

void Skeleton::NotifyObservers(TileMap &map, sf::RenderWindow &window) {
}

