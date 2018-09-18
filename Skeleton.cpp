//
// Created by nicola on 8/28/18.
//

#include "Skeleton.h"

Skeleton::~Skeleton() {};


void Skeleton::Update(float deltaTime, sf::RenderWindow &window) {

    int init = rand()%4;
    sf::Vector2f movement(0.0f, 0.0f);


    if (init==0) {// && body.getPosition().x >= 0) {
        movement.x -= this->speed * deltaTime;
        row = 3;
    }
    if (init==1) {// && body.getPosition().x + body.getLocalBounds().width <= window.getSize().x) {
        movement.x += this->speed * deltaTime;
        row = 1;
    }
    if (init==2) {// && body.getPosition().y >=-40) {
        movement.y -= this->speed * deltaTime;
        row = 0;
    }
    if (init==3) {// && body.getPosition().y+ body.getLocalBounds().width <= window.getSize().y-60) {
        movement.y += this->speed * deltaTime;
        row = 2;
    }

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
    playerBorder.move(movement);

}

void Skeleton::Create(float deltatime, sf::RenderWindow &window) {
    RangedCharacter::Create(deltatime, window);
    Skeleton::Update(deltatime, window);
}