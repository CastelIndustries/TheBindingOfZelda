//
// Created by nicola on 9/1/18.
//

#include "MeleeCharacterFactory.h"

std::unique_ptr<Character> MeleeCharacterFactory::Create(std::string type, sf::Texture *texture,
                                                         sf::Vector2u imageCount, float switchTime, float speed) {

    if (type == "ghost") {
        std::unique_ptr<Character> ghost(new Ghost(texture, imageCount, switchTime, speed));
        return ghost;
    } else {
        std::unique_ptr<Character> rabbit(new KungFuRabbit(texture, imageCount, switchTime, speed));
        return rabbit;
    }
}