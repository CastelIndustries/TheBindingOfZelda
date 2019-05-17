#include <iostream>
#include <SFML/Graphics.hpp>
#include "googletest-master/googletest/include/gtest/gtest.h"
#include "../Player.h"
#include "../Skeleton.h"
#include "../Ghost.h"
#include "../KungFuRabbit.h"
#include "iostream"
#include <list>
#include "../CharacterFactory.h"


int main() {
    sf::Texture playerTexture;
    sf::Texture rabbitTexture;
    sf::Texture skeletonTexture;
    sf::Texture ghostTexture;

    std::list<std::unique_ptr<Character>> characterList;
    CharacterFactory characterFactory;

    characterList.push_back(characterFactory.Create(type::PLAYER, &playerTexture, sf::Vector2u(3, 4), 0.1f, 300.0f));
    characterList.push_back(characterFactory.Create(type::RABBIT, &rabbitTexture, sf::Vector2u(6, 4), 0.1f, 200.0f));
    characterList.push_back(
            characterFactory.Create(type::SKELETON, &skeletonTexture, sf::Vector2u(3, 4), 0.2f, 300.0f));
    characterList.push_back(characterFactory.Create(type::GHOST, &ghostTexture, sf::Vector2u(3, 4), 0.1f, 200.f));


    //TEST()
    return 0;
}