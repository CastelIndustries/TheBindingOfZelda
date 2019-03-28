//
// Created by nicola on 8/30/18.
//

#ifndef SFML_TESTS_LINK_KUNGFURABBIT_H
#define SFML_TESTS_LINK_KUNGFURABBIT_H

#include <random>
#include "MeleeCharacter.h"

class KungFuRabbit : public MeleeCharacter {

public:

    ~KungFuRabbit();

    virtual void Create(float deltaTime, sf::RenderWindow &window) override;

    void Update(float deltaTime, sf::RenderWindow &window) override;

    void CorrectDisplay(sf::RenderWindow &window) override;

    float init;



    void MeleeAttack() override {};                             //TO DO

    KungFuRabbit(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : MeleeCharacter(texture,
                                                                                                                imageCount,
                                                                                                                switchTime,
                                                                                                                speed) {
            std::uniform_int_distribution<int> distrX(2963, 8280);
            std::uniform_int_distribution<int> distrY(1757, 4336);
            std::random_device generator;
            std::mt19937 eng(generator());
            this->speed = speed;
            dash = speed;
            row = 2;
            body.setSize(sf::Vector2f(120.0f, 210.0f));
            body.setPosition(distrX(eng), distrY(eng));
            body.setTexture(texture);
            //body.setFillColor(sf::Color::White);
            clock.restart();
    }
};

#endif //SFML_TESTS_LINK_KUNGFURABBIT_H
