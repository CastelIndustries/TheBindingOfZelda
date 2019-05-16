//
// Created by nicola on 8/28/18.
//

#include "Character.h"
#include "Animation.h"

#include <iostream>

Character::Character(std::string filename, sf::Vector2u imageCount, float switchTime, float speed) : animation(filename,
                                                                                                               imageCount,
                                                                                                               switchTime) {


};

Character::~Character() {}


void Character::Draw(sf::RenderWindow &window) {
    window.draw(body);
}

void Character::RangedAttack() {}

void Character::Create(float deltaTime, sf::RenderWindow &window) {
    this->Update(deltaTime, window);
    this->Draw(window);
};
