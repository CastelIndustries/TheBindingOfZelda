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
    virtual void Update(float deltaTime, sf::RenderWindow &window) override;

    virtual void Draw(sf::RenderWindow &window) override;

    virtual void CorrectDisplay(sf::RenderWindow &window) override;

    virtual void MeleeAttack() {};                           //TODO

};


#endif //SFML_TESTS_LINK_MELEECHARACTER_H
