//
// Created by nicola on 8/30/18.
//

#ifndef SFML_TESTS_LINK_MELEECHARACTER_H
#define SFML_TESTS_LINK_MELEECHARACTER_H

#include "Character.h"

class MeleeCharacter : public Character {
public:

    virtual    ~MeleeCharacter() {};

protected:


    MeleeCharacter(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : Character(texture,
                                                                                                             imageCount,
                                                                                                             switchTime,
                                                                                                             speed) {}


    virtual void MeleeAttack() {};                           //TODO

    virtual void Create(float deltatime, sf::RenderWindow &window) override;

    virtual void Update(float deltatime, sf::RenderWindow &window) override =0;

};


#endif //SFML_TESTS_LINK_MELEECHARACTER_H
