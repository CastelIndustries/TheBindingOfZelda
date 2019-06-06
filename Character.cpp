//
// Created by nicola on 8/28/18.
//

#include "Character.h"
#include "Animation.h"
#include "DEFINITIONS.h"
#include <cmath>

#include <iostream>

Character::Character(std::string filename, sf::Vector2u imageCount, float switchTime, float speed) : animation(filename,
                                                                                                               imageCount,
                                                                                                               switchTime) {


};

Character::~Character() {}


void Character::Draw(sf::RenderWindow &window) {
    window.draw(body);
}

void Character::Create(float deltaTime, sf::RenderWindow &window) {
    this->Update(deltaTime, window);
    this->Draw(window);
}

void Character::Attack(Character &player, float deltaTime, sf::RenderWindow &window) {
    distance=sqrt(pow(body.getPosition().x - player.body.getPosition().x, 2 ) + pow(body.getPosition().y - player.body.getPosition().y, 2));

    if(distance < RANGE){
        this->ArtificialIntelligence(player, deltaTime, window);
    }
};
