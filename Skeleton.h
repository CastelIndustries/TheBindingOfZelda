//
// Created by nicola on 8/28/18.
//

#ifndef SFML_TESTS_LINK_SKELETON_H
#define SFML_TESTS_LINK_SKELETON_H

#include "RangedCharacter.h"

class Skeleton : public RangedCharacter {
public:
    Skeleton(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : RangedCharacter(texture,
                                                                                                             imageCount,
                                                                                                             switchTime,
                                                                                                             speed) {};

    ~Skeleton();

    void Update(float deltaTime, sf::RenderWindow &window);

    void RangedAttack() override {};                    //TODO

    void Create(float deltaTime, sf::RenderWindow &window) override;
};


#endif //SFML_TESTS_LINK_SKELETON_H
