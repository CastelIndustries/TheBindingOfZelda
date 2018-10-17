//
// Created by nicola on 8/31/18.
//

#ifndef SFML_TESTS_LINK_CHARACTERFACTORY_H
#define SFML_TESTS_LINK_CHARACTERFACTORY_H

#include "Character.h"

class CharacterFactory {
public:
    CharacterFactory() {};

    virtual ~CharacterFactory() {};

    virtual std::unique_ptr<Character>
    Create(std::string type, sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);
};


#endif //SFML_TESTS_LINK_CHARACTERFACTORY_H
