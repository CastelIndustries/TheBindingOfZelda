//
// Created by nicola on 8/30/18.
//

#ifndef SFML_TESTS_LINK_RANGEDCHARACTER_H
#define SFML_TESTS_LINK_RANGEDCHARACTER_H

#include "Character.h"
#include "Bullet.h"

class RangedCharacter : public Character{

public:
    RangedCharacter() {};
    virtual    ~RangedCharacter() {};


    RangedCharacter(std::string filename, sf::Vector2u imageCount, float switchTime, float speed) : Character(filename,
                                                                                                              imageCount,
                                                                                                              switchTime,
                                                                                                              speed) {}

    void Create(float deltaTime, sf::RenderWindow &window) override;

    void Update(float deltaTime, sf::RenderWindow &window) override;

    void RangedAttack () override ;

    void Attack(Character &player, float deltaTime, sf::RenderWindow &window) override;

    void ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) override;

    void MeleeAttack(Character &character) override;

    void Draw(sf::RenderWindow &window) override;


protected:
    float init;

    bool check = false;





};


#endif //SFML_TESTS_LINK_RANGEDCHARACTER_H
