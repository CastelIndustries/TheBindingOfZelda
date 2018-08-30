//
// Created by nicola on 8/28/18.
//

#include "Character.h"
#include "Animation.h"

#include <iostream>

Character::Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture,
                                                                                                               imageCount,
                                                                                                               switchTime) {

    this->speed = speed;
    dash = speed;
    row = 2;
    body.setSize(sf::Vector2f(120.0f, 210.0f));
    body.setPosition(336.0f, 336.0f);
    body.setTexture(texture);
    playerBorder.setSize(sf::Vector2f(80.0f, 150.0f));
    playerBorder.setPosition(body.getPosition().x + 20, body.getPosition().y + 20);
    playerBorder.setFillColor(sf::Color::Transparent);
};

Character::~Character() {}

void Character::Update(float deltaTime, sf::RenderWindow &window) {
    sf::Vector2f movement(0.0f, 0.0f);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {// && body.getPosition().x >= 0) {
        movement.x -= speed * deltaTime;
        row = 3;
    }
    if (sf::Keyboard::isKeyPressed(
            sf::Keyboard::D)) {// && body.getPosition().x + body.getLocalBounds().width <= window.getSize().x) {
        movement.x += speed * deltaTime;
        row = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {// && body.getPosition().y >=-40) {
        movement.y -= speed * deltaTime;
        row = 0;
    }
    if (sf::Keyboard::isKeyPressed(
            sf::Keyboard::S)) {// && body.getPosition().y+ body.getLocalBounds().width <= window.getSize().y-60) {
        movement.y += speed * deltaTime;
        row = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        speed = dash * 2;
    else
        speed = dash;

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
    playerBorder.move(movement);

}

void Character::Draw(sf::RenderWindow &window) {
    window.draw(body);
    window.draw(playerBorder);
}

void Character::CorrectDisplay(sf::RenderWindow &window) {

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

