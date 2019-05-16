//
// Created by nicola on 8/31/18.
//

#include "CharacterFactory.h"
#include "Player.h"
#include "Skeleton.h"
#include "Ghost.h"
#include "KungFuRabbit.h"

std::unique_ptr<Character> CharacterFactory::Create(type t, std::string filename, sf::Vector2u imageCount,
                                                    float switchTime, float speed) {

    if (t == type::PLAYER) {
        std::unique_ptr<Player> player(new Player(filename, imageCount, switchTime, speed));
        return player;
    }

    if (t == type::SKELETON) {
        std::unique_ptr<Skeleton> skeleton(new Skeleton(filename, imageCount, switchTime, speed));
        return skeleton;
    }

    if (t == type::GHOST) {
        std::unique_ptr<Ghost> ghost(new Ghost(filename, imageCount, switchTime, speed));
        return ghost;
    } else {
        std::unique_ptr<KungFuRabbit> rabbit(new KungFuRabbit(filename, imageCount, switchTime, speed));
        return rabbit;
    }
}

