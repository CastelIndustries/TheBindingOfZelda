//
// Created by nicola on 8/30/18.
//

#ifndef SFML_TESTS_LINK_RANGEDCHARACTER_H
#define SFML_TESTS_LINK_RANGEDCHARACTER_H

#include "Character.h"
#include "Bullet.h"

class RangedCharacter : public Character {

public:
    RangedCharacter() {};
    virtual    ~RangedCharacter() {};

protected:
    RangedCharacter(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : Character(texture,
                                                                                                              imageCount,
                                                                                                              switchTime,
                                                                                                              speed) {}

    void Create(float deltaTime, sf::RenderWindow &window) override;

    void Update(float deltaTime, sf::RenderWindow &window) override;

    virtual void RangedAttack ()override ;

    virtual void ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) override;

    float init;

    float range = 100.0f;

    bool Check = false;





};


#endif //SFML_TESTS_LINK_RANGEDCHARACTER_H
