//
// Created by nicola on 8/30/18.
//

#ifndef SFML_TESTS_LINK_RANGEDCHARACTER_H
#define SFML_TESTS_LINK_RANGEDCHARACTER_H

#include "Character.h"

class RangedCharacter : public Character {

public:
    RangedCharacter() {};
    virtual    ~RangedCharacter() {};

protected:
    RangedCharacter(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : Character(texture,
                                                                                                              imageCount,
                                                                                                              switchTime,
                                                                                                              speed) {}

    virtual void Create(float deltatime, sf::RenderWindow &window) override;

    virtual void Update(float deltatime, sf::RenderWindow &window) override =0;

    virtual void RangedAttack() {};              // TODO

};


#endif //SFML_TESTS_LINK_RANGEDCHARACTER_H
