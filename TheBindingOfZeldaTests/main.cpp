#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "../Skeleton.h"
#include "../Ghost.h"
#include "../KungFuRabbit.h"
#include "iostream"
#include <list>
#include "../CharacterFactory.h"
#include "googletest/include/gtest/gtest.h"


TEST(Collisions, CollisionsTests) {

}

int main() {
    sf::RenderWindow window(sf::VideoMode(1211, 865), "The Binding of Zelda", sf::Style::Close);
    sf::Texture playerTexture;
    sf::Texture rabbitTexture;
    sf::Texture skeletonTexture;
    sf::Texture ghostTexture;
    sf::Clock clock;
    float deltaTime = clock.restart().asSeconds();

    std::list<std::unique_ptr<Character>> characterList;
    CharacterFactory characterFactory;

    characterList.push_back(characterFactory.Create(type::PLAYER, &playerTexture, sf::Vector2u(3, 4), 0.1f, 300.0f));
    characterList.push_back(characterFactory.Create(type::RABBIT, &rabbitTexture, sf::Vector2u(6, 4), 0.1f, 200.0f));
    characterList.push_back(
            characterFactory.Create(type::SKELETON, &skeletonTexture, sf::Vector2u(3, 4), 0.2f, 300.0f));
    characterList.push_back(characterFactory.Create(type::GHOST, &ghostTexture, sf::Vector2u(3, 4), 0.1f, 200.f));
    window.clear();



    return 0;
}