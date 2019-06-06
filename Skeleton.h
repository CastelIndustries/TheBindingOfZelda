//
// Created by nicola on 8/28/18.
//

#ifndef SFML_TESTS_LINK_SKELETON_H
#define SFML_TESTS_LINK_SKELETON_H

#include <random>
#include "RangedCharacter.h"

class Skeleton : public RangedCharacter {
public:
    Skeleton(std::string filename, sf::Vector2u imageCount, float switchTime, float speed) : RangedCharacter(filename,
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
            skeletonTexture.loadFromFile(filename);
            body.setTexture(&skeletonTexture);
            this->ShootDelay = sf::seconds(2.0f);
    };

    ~Skeleton();

    void Attack(Character &player, float deltaTime, sf::RenderWindow &window) override;

    void RangedAttack() override;

    void Create(float deltaTime, sf::RenderWindow &window) override;

    void Update(float deltaTime, sf::RenderWindow &window) override;

    void ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) override;

    void MeleeAttack(Character &character) override;

    void Draw(sf::RenderWindow &window) override;


private:
    sf::Texture skeletonTexture;

};


#endif //SFML_TESTS_LINK_SKELETON_H
