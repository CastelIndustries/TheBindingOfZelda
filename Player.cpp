//
// Created by frangio on 24/04/18.
//

#include "Player.h"

void Player::Update(float deltaTime, sf::RenderWindow &window) {
    sf::Vector2f movement(0.0f, 0.0f);

    bool stop = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {// && body.getPosition().x >= 0) {
        movement.x -= this->speed * deltaTime;
        this->row = 2;
    } else {

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

    if (stop) {
        this->animation.StopUpdate(this->row);
    } else
        this->animation.Update(this->row, deltaTime);

    this->body.setTextureRect(this->animation.uvRect);
    this->body.move(movement);
    this->playerBorder.move(movement);

}

void Player::CorrectDisplay(sf::RenderWindow &window) {

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

void Player::Create(float deltatime, sf::RenderWindow &window) {
    Player::Update(deltatime, window);
    RangedCharacter::Draw(window);
    Player::CorrectDisplay(window);
}
Player::~Player() {};

