//
// Created by frangio on 25/04/18.
//

#include "Coin.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"


Coin::Coin(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, int value, float posX, float posY): animation(texture, imageCount, switchTime) {


    body.setSize(sf::Vector2f(50.0f, 50.0f));
    body.setPosition(posX, posY);
    body.setTexture(texture);
    coinBorder.setSize(sf::Vector2f(30.0f, 30.0f));
    coinBorder.setPosition(posX+10, posY+10);
    coinBorder.setFillColor(sf::Color::Transparent);

}

Coin::~Coin() {}

void Coin::rotate(float deltaTime){

    animation.Update(0, deltaTime);
    body.setTextureRect(animation.uvRect);

}

void Coin::Draw(sf::RenderWindow& window)
{
    window.draw(body);
    window.draw(coinBorder);
}





