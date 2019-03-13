//
// Created by nicola on 8/28/18.
//

#ifndef SFML_TESTS_LINK_CHARACTER_H
#define SFML_TESTS_LINK_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "time.h"
#include "Collider.h"
#include "vector"
#include "Bullet.h"
#include "iostream"

class Character {

public:

    sf::RectangleShape body;

    sf::Clock clock;

    Character();

    virtual  ~Character();

    virtual void Update(float deltaTime, sf::RenderWindow &window)=0;

    virtual void Draw(sf::RenderWindow &window);

    virtual void CorrectDisplay(sf::RenderWindow &window)=0;

    virtual void Create(float deltaTime, sf::RenderWindow &window);

    virtual void RangedAttack();

    Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);

    Collider GetCollider() {
        return Collider(body);
    }

    bool isFiring= false;

    int dirRanAtt;


//protected:
    float speed, dash;

    Animation animation;
    unsigned int row;

};


#endif //SFML_TESTS_LINK_CHARACTER_H
