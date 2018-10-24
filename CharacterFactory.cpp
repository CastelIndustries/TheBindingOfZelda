//
// Created by nicola on 8/31/18.
//

#include "CharacterFactory.h"
#include "Player.h"
#include "Skeleton.h"
#include "Ghost.h"
#include "KungFuRabbit.h"

std::unique_ptr<Character> CharacterFactory::Create(type t, sf::Texture *texture, sf::Vector2u imageCount,
                                                    float switchTime, float speed) {

    if (t == type::PLAYER) {
        std::unique_ptr<Character> player(new Player(texture, imageCount, switchTime, speed));
        return player;
    }

    if (t == type::SKELETON) {
        std::unique_ptr<Character> skeleton(new Skeleton(texture, imageCount, switchTime, speed));
        return skeleton;
    }

    if (t == type::GHOST) {
        std::unique_ptr<Character> ghost(new Ghost(texture, imageCount, switchTime, speed));
        return ghost;
    } else {
        std::unique_ptr<Character> rabbit(new KungFuRabbit(texture, imageCount, switchTime, speed));
        return rabbit;
    }
}

