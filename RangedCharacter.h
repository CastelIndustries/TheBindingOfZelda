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
    RangedCharacter(std::string filename, sf::Vector2u imageCount, float switchTime, float speed) : Character(filename,
                                                                                                              imageCount,
                                                                                                              switchTime,
                                                                                                              speed) {}

    void Create(float deltaTime, sf::RenderWindow &window) override;

    void Update(float deltaTime, sf::RenderWindow &window) override;

    virtual void RangedAttack ()override ;

    virtual void ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) override;

    void  Punch (std::unique_ptr<Character>& enemy) override {};

    float init;

    float range = 25.0f;

    bool Check = false;





};


#endif //SFML_TESTS_LINK_RANGEDCHARACTER_H
