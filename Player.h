//
// Created by frangio on 24/04/18.
//


#ifndef SFML_TESTS_PLAYER_H
#define SFML_TESTS_PLAYER_H


#include "RangedCharacter.h"

class Player : public RangedCharacter {
public:

    Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : RangedCharacter(texture,
                                                                                                           imageCount,
                                                                                                           switchTime,
                                                                                                           speed) {};
    ~Player();

    void RangedAttack() override {};                            //TO DO

    void Create(float deltatime, sf::RenderWindow &window) override;
};


#endif //SFML_TESTS_PLAYER_H
