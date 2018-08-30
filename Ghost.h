//
// Created by nicola on 8/30/18.
//

#ifndef SFML_TESTS_LINK_GHOST_H
#define SFML_TESTS_LINK_GHOST_H

#include "MeleeCharacter.h"

class Ghost : MeleeCharacter {
    Ghost(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : MeleeCharacter(texture,
                                                                                                         imageCount,
                                                                                                         switchTime,
                                                                                                         speed) {}

    virtual void Update(float deltaTime, sf::RenderWindow &window) override;

    virtual void Draw(sf::RenderWindow &window) override;

    virtual void CorrectDisplay(sf::RenderWindow &window) override;

    void MeleeAttack() override {};                             //TO DO

};


#endif //SFML_TESTS_LINK_GHOST_H
