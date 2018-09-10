//
// Created by nicola on 8/30/18.
//

#ifndef SFML_TESTS_LINK_KUNGFURABBIT_H
#define SFML_TESTS_LINK_KUNGFURABBIT_H

#include "MeleeCharacter.h"

class KungFuRabbit : public MeleeCharacter {

public:

    ~KungFuRabbit();

    virtual void Create(float deltatime, sf::RenderWindow &window) override;

    void MeleeAttack() override {};                             //TO DO

    KungFuRabbit(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : MeleeCharacter(texture,
                                                                                                                imageCount,
                                                                                                                switchTime,
                                                                                                                speed) {}
};

#endif //SFML_TESTS_LINK_KUNGFURABBIT_H
