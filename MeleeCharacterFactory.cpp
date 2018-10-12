//
// Created by nicola on 9/1/18.
//

#include "MeleeCharacterFactory.h"

std::unique_ptr<Character> MeleeCharacterFactory::Create(type t, sf::Texture *texture,
                                                         sf::Vector2u imageCount, float switchTime, float speed) {
    Character* character = NULL;
    switch (t) {

        case type::GHOST :
            character = new Ghost(texture, imageCount, switchTime, speed);
            break;
        case type::RABBIT :
            character = new KungFuRabbit(texture, imageCount, switchTime, speed);
            break;
        default :break;
    }
    std::unique_ptr<Character> c(character);
    return c;
}