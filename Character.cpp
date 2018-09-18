//
// Created by nicola on 8/28/18.
//

#include "Character.h"
#include "Animation.h"

#include <iostream>

Character::Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture,
                                                                                                               imageCount,
                                                                                                               switchTime) {
    sf::RenderWindow window(sf::VideoMode(1211, 865), "Legend of Zelda", sf::Style::Close);
    this->speed = speed;
    dash = speed;
    row = 2;
    body.setSize(sf::Vector2f(120.0f, 210.0f));
    body.setPosition(rand()%(window.getSize().x- (int)body.getPosition().x), rand()%(window.getSize().y-(int)body.getPosition().y));
    body.setTexture(texture);
    playerBorder.setSize(sf::Vector2f(80.0f, 150.0f));
    playerBorder.setPosition(body.getPosition().x + 20, body.getPosition().y + 20);
    playerBorder.setFillColor(sf::Color::Transparent);
    clock.restart();
};

Character::~Character() {}


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

void Character::Create(float deltatime, sf::RenderWindow &window) {
    this->Draw(window);
    this->CorrectDisplay(window);
};
