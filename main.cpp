#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Animation.h"
#include "Player.h"
#include "Maps.h"
#include "Element.h"
#include "RangedCharacterFactory.h"
#include "MeleeCharacterFactory.h"
#include <ctime>
#include "Platform.h"

int main() {
    //WINDOW
    sf::RenderWindow window(sf::VideoMode(1211, 865), "The Binding of Zelda", sf::Style::Close);
    srand((unsigned) time(nullptr));
    Maps map;

    //PLAYER
    RangedCharacterFactory PlayerFactory;
    sf::Texture playerTexture;
    playerTexture.loadFromFile("../Textures/FRANCO DEFINITIVO.png");

    //auto player = PlayerFactory.Create(type::PLAYER, &playerTexture, sf::Vector2u(3, 4), 0.1f, 200.0f);
    Player player(&playerTexture, sf::Vector2u(3, 4), 0.1f, 200.0f);


    //ENEMIES
    MeleeCharacterFactory RabbitFactory;
    RangedCharacterFactory SkeletonFactory;
    MeleeCharacterFactory GhostFactory;
    Platform platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 500.0f));
    Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));

    sf::Texture rabbitTexture;
    sf::Texture skeletonTexture;
    sf::Texture ghostTexture;

    rabbitTexture.loadFromFile("../Textures/rabbit.png");
    skeletonTexture.loadFromFile("../Textures/skeletonChar.png");
    ghostTexture.loadFromFile("../Textures/ghost.png");

    //auto rabbit = RabbitFactory.Create(type::RABBIT, &rabbitTexture, sf::Vector2u(6, 4), 0.1f, 200.0f);
    //auto skeleton = SkeletonFactory.Create(type::SKELETON, &skeletonTexture, sf::Vector2u(9, 4), 0.1f, 200.0f);
    //auto ghost = GhostFactory.Create(type::GHOST, &ghostTexture, sf::Vector2u(3 , 4), 0.1f, 200.f);


    //ELEMENTS
    std::vector<Element*> elements;

    elements.push_back(new Element(175, 175, "../Textures/tesoro-b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 1b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 2b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 3b.png", 0.3, 0.3));

    //if(player.playerBorder.getGlobalBounds().intersects(coins[i]->coinBorder.getGlobalBounds())){
   /* if(player->playerBorder.getGlobalBounds().intersects(rabbit->playerBorder.getGlobalBounds())){

    }*/


    float deltaTime;

    sf::Clock clock;
    int count=0;
    float time1;

    while (window.isOpen())

    {
        deltaTime = clock.restart().asSeconds();


        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

           }





        }
        //WINDOW
        window.clear();
        map.showMaps(window);

        //ELEMENTS

        for(auto element:elements){
            element->Draw(window);
        }


        //PLAYER
        player.Create(deltaTime, window);

        //ENEMIES
        platform.getCollider().checkCollision(player.getCollider(), 0.0f);
        platform1.getCollider().checkCollision(player.getCollider(), 0.0f);

        platform.Draw(window);
        platform1.Draw(window);


        //rabbit->Create(deltaTime, window);
        //ghost->Create(deltaTime, window);
        //skeleton->Create(deltaTime, window);
        //rabbit->getCollider().checkCollision(player->getCollider(), 1.0f);
        //skeleton->getCollider().checkCollision(player->getCollider(), 1.0f);
        //ghost->getCollider().checkCollision(player->getCollider(), 1.0f);


        window.display();
    }

    return 0;
}