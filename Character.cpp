//
// Created by nicola on 8/28/18.
//

#include "Character.h"
#include "Animation.h"

#include <iostream>

Character::Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture,
                                                                                                               imageCount,
                                                                                                               switchTime) {

};

Character::~Character() {}


void Character::Draw(sf::RenderWindow &window) {
    window.draw(body);
    window.draw(playerBorder);
}


void Character::Create(float deltatime, sf::RenderWindow &window) {
    this->Update(deltatime, window);
    this->Draw(window);
    this->CorrectDisplay(window);
};
