//
// Created by nicola on 8/30/18.
//

#ifndef SFML_TESTS_LINK_GHOST_H
#define SFML_TESTS_LINK_GHOST_H

#include "MeleeCharacter.h"

class Ghost : public MeleeCharacter {
public:

    ~Ghost();


    virtual void Create(float deltaTime, sf::RenderWindow &window);

    virtual void Update(float deltatime, sf::RenderWindow &window) override;

    void CorrectDisplay(sf::RenderWindow &window) override;

    float init;

    void MeleeAttack() override {};                            //TO DO

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
            }
};


#endif //SFML_TESTS_LINK_GHOST_H
