//
// Created by nicola on 9/1/18.
//

#ifndef SFML_TESTS_LINK_MELEECHARACTERFACTORY_H
#define SFML_TESTS_LINK_MELEECHARACTERFACTORY_H

#include "CharacterFactory.h"
#include "Ghost.h"
#include "KungFuRabbit.h"


class MeleeCharacterFactory : public CharacterFactory {
public:
    MeleeCharacterFactory() {};

    ~MeleeCharacterFactory() {};

    std::unique_ptr<Character>
    Create(std::string type, sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) override;

};


#endif //SFML_TESTS_LINK_MELEECHARACTERFACTORY_H
