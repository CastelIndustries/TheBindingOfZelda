//
// Created by frangio on 24/04/18.
//

#include "Player.h"

void Player::Update(float deltaTime, sf::RenderWindow &window) {

        sf::Vector2f movement(0.0f, 0.0f);


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){// && body.getPosition().x >= 0) {
            movement.x -= this->speed * deltaTime;
            row = 3;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){// && body.getPosition().x + body.getLocalBounds().width <= window.getSize().x) {
            movement.x += this->speed * deltaTime;
            row=1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){// && body.getPosition().y >=-40) {
            movement.y -= this->speed * deltaTime;
            row = 0;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){// && body.getPosition().y+ body.getLocalBounds().width <= window.getSize().y-60) {
            movement.y += this->speed * deltaTime;
            row = 2;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            this->speed = dash*2;
        else
            this->speed=dash;

        animation.Update(row, deltaTime);
        body.setTextureRect(animation.uvRect);
        body.move(movement);
        playerBorder.move(movement);

}

void Player::Create(float deltaTime, sf::RenderWindow &window) {
    RangedCharacter::Create(deltaTime, window);
    Player::Update(deltaTime, window);
}

Player::~Player() {};

