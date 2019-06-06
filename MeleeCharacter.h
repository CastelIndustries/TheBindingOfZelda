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

    MeleeCharacter(std::string filename, sf::Vector2u imageCount, float switchTime, float speed) : Character(filename,
                                                                                                             imageCount,
                                                                                                             switchTime,
                                                                                                             speed) {}


    void Create(float deltaTime, sf::RenderWindow &window) override;

    void Update(float deltaTime, sf::RenderWindow &window) override;

    void Attack(Character &player, float deltaTime, sf::RenderWindow &window) override;

    void ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) override;

    void MeleeAttack(Character &character) override;

    void RangedAttack() override;

    void Draw(sf::RenderWindow &window) override;


protected:
    float init;

    bool check = false;

};


#endif //SFML_TESTS_LINK_MELEECHARACTER_H
