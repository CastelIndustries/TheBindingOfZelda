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

    void Update(float deltaTime, sf::RenderWindow &window);

    void MeleeAttack() override {};                             //TO DO

    Ghost(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : MeleeCharacter(texture,
                                                                                                         imageCount,
                                                                                                         switchTime,
                                                                                                         speed) {}
};


#endif //SFML_TESTS_LINK_GHOST_H
