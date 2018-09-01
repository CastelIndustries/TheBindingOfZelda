//
// Created by nicola on 8/31/18.
//

#include "RangedCharacterFactory.h"


std::unique_ptr<Character> RangedCharacterFactory::Create(std::string type, sf::Texture *texture,
                                                          sf::Vector2u imageCount, float switchTime, float speed) {

    if (type == "player") {
        std::unique_ptr<Character> player(new Player(texture, imageCount, switchTime, speed));
        return player;
    } else {
        std::unique_ptr<Character> skeleton(new Skeleton(texture, imageCount, switchTime, speed));
        return skeleton;
    }
}


