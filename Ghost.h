//
// Created by nicola on 8/30/18.
//

#ifndef SFML_TESTS_LINK_GHOST_H
#define SFML_TESTS_LINK_GHOST_H

#include "MeleeCharacter.h"

class Ghost : public MeleeCharacter {
public:
    Ghost(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : MeleeCharacter(texture,
                                                                                                         imageCount,
                                                                                                         switchTime,
                                                                                                         speed) {
        this->speed = speed;
        dash = speed;
        row = 2;
        body.setSize(sf::Vector2f(120.0f, 210.0f));
        body.setPosition(rand() % 1211, rand() % 865);
        body.setTexture(texture);
        playerBorder.setSize(sf::Vector2f(80.0f, 150.0f));
        playerBorder.setPosition(body.getPosition().x, body.getPosition().y);
        playerBorder.setFillColor(sf::Color::Yellow);
        clock.restart();
    }

    ~Ghost();


    virtual void Create(float deltaTime, sf::RenderWindow &window) override;

    virtual void Update(float deltaTime, sf::RenderWindow &window) override ;

    void CorrectDisplay(sf::RenderWindow &window) override;

    float init;

    void MeleeAttack() override {};                             //TODO


};


#endif //SFML_TESTS_LINK_GHOST_H
