//
// Created by nicola on 8/28/18.
//

#ifndef SFML_TESTS_LINK_SKELETON_H
#define SFML_TESTS_LINK_SKELETON_H

#include "RangedCharacter.h"

class Skeleton : public RangedCharacter {
public:
    Skeleton(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : RangedCharacter(texture,
                                                                                                             imageCount,
                                                                                                             switchTime,
                                                                                                             speed) {
        this->speed = speed;
        dash = speed;
        row = 2;
        body.setSize(sf::Vector2f(120.0f, 210.0f));
        body.setPosition(rand() % 1211, rand() % 865);
        body.setTexture(texture);
        //body.setFillColor(sf::Color::White);
    };

    ~Skeleton();

    void RangedAttack() override {};                    //TO DO

    virtual void Update(float deltatime, sf::RenderWindow &window) override;

    virtual void Create(float deltatime, sf::RenderWindow &window) override;

    void CorrectDisplay(sf::RenderWindow &window) override;

    float init;
};


#endif //SFML_TESTS_LINK_SKELETON_H
