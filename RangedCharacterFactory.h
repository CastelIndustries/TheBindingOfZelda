//
// Created by nicola on 8/31/18.
//

#ifndef SFML_TESTS_LINK_RANGEDCHARACTERFACTORY_H
#define SFML_TESTS_LINK_RANGEDCHARACTERFACTORY_H

#include "CharacterFactory.h"
#include "Player.h"
#include "Skeleton.h"

class RangedCharacterFactory : public CharacterFactory {
public:
    RangedCharacterFactory() {};

    ~RangedCharacterFactory() {};

    std::unique_ptr<Character>
    Create(std::string type, sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) override;
};


#endif //SFML_TESTS_LINK_RANGEDCHARACTERFACTORY_H
