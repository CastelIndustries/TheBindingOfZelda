//
// Created by nicola on 8/30/18.
//

#ifndef SFML_TESTS_LINK_MELEECHARACTER_H
#define SFML_TESTS_LINK_MELEECHARACTER_H

#include "Character.h"

class MeleeCharacter : public Character {
public:
    MeleeCharacter() {};
    virtual    ~MeleeCharacter() {};

protected:


    MeleeCharacter(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : Character(texture,
                                                                                                             imageCount,
                                                                                                             switchTime,
                                                                                                             speed) {}


    virtual void MeleeAttack() {};                           //TODO

    virtual void Create(float deltaTime, sf::RenderWindow &window) override;

    virtual void Update(float deltaTime, sf::RenderWindow &window) override =0;

    virtual void ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) override {};

};


#endif //SFML_TESTS_LINK_MELEECHARACTER_H
