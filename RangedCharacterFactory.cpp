//
// Created by nicola on 8/31/18.
//

#include "RangedCharacterFactory.h"


std::unique_ptr<Character> RangedCharacterFactory::Create(type t, sf::Texture *texture,
                                                          sf::Vector2u imageCount, float switchTime, float speed) {

    Character* character = NULL;
    switch (t) {

        case type::PLAYER :
            character = new Player(texture, imageCount, switchTime, speed);
            break;
        case type::SKELETON :
            character = new Skeleton(texture, imageCount, switchTime, speed);
            break;
        default :break;
    }
    std::unique_ptr<Character> c(character);
    return c;
}


