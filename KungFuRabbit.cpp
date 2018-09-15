//
// Created by nicola on 8/30/18.
//

#include "KungFuRabbit.h"

void KungFuRabbit::Update(float deltaTime, sf::RenderWindow &window) {

    sf::Vector2f movement(0.0f, 0.0f);
    if (clock.getElapsedTime().asSeconds() > 3) {
        init = rand() % 4;
        clock.restart();
    }

    if (init == 0) {// && body.getPosition().x >= 0) {
        movement.x -= this->speed * deltaTime;
        row = 3;
    }
    if (init == 1) {// && body.getPosition().x + body.getLocalBounds().width <= window.getSize().x) {
        movement.x += this->speed * deltaTime;
        row = 1;
    }
    if (init == 2) {// && body.getPosition().y >=-40) {
        movement.y -= this->speed * deltaTime;
        row = 0;
    }
    if (init == 3) {// && body.getPosition().y+ body.getLocalBounds().width <= window.getSize().y-60) {
        movement.y += this->speed * deltaTime;
        row = 2;
    }

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
    playerBorder.move(movement);


}

void KungFuRabbit::CorrectDisplay(sf::RenderWindow &window) {
    if (body.getPosition().x <= 0) {
        body.setPosition(0, body.getPosition().y);
        playerBorder.setPosition(body.getPosition().x + 20, body.getPosition().y + 20);
    }
    if (body.getPosition().x + body.getGlobalBounds().width >= window.getSize().x) {
        body.setPosition(window.getSize().x - body.getSize().x, body.getPosition().y);
        playerBorder.setPosition(body.getPosition().x + 20, body.getPosition().y + 20);
    }
    if (body.getPosition().y <= 0) {
        body.setPosition(body.getPosition().x, 0);
        playerBorder.setPosition(body.getPosition().x + 20, body.getPosition().y + 20);
    }
    if (body.getPosition().y + body.getGlobalBounds().height >= window.getSize().y) {
        body.setPosition(body.getPosition().x, window.getSize().y - body.getSize().y);
        playerBorder.setPosition(body.getPosition().x + 20, body.getPosition().y + 20);
    }
}



void KungFuRabbit::Create(float deltatime, sf::RenderWindow &window) {
    KungFuRabbit::Update(deltatime, window);
    MeleeCharacter::Draw(window);
    KungFuRabbit::CorrectDisplay(window);

}
KungFuRabbit::~KungFuRabbit() {}