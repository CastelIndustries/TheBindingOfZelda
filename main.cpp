#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Animation.h"
#include "Player.h"
#include "Maps.h"
#include "Element.h"
#include "CharacterFactory.h"
#include <ctime>

int main() {
    //WINDOW
    sf::RenderWindow window(sf::VideoMode(1211, 865), "The Binding of Zelda", sf::Style::Close);
    srand((unsigned) time(nullptr));
    Maps map1(0);
    Maps map2(window.getSize().x+100);
    //Maps map3;
    sf::View view(sf::Vector2f(336.0f, 336.0f), sf::Vector2f(1211, 865));

    //PLAYERS
    CharacterFactory PlayerFactory;
    sf::Texture playerTexture;
    playerTexture.loadFromFile("../Textures/FRANCO DEFINITIVO.png");

    auto player = PlayerFactory.Create(type::PLAYER, &playerTexture, sf::Vector2u(3, 4), 0.1f, 200.0f);


    //ENEMIES
    CharacterFactory EnemiesFactory;

    sf::Texture rabbitTexture;
    sf::Texture skeletonTexture;
    sf::Texture ghostTexture;

    rabbitTexture.loadFromFile("../Textures/rabbit.png");
    skeletonTexture.loadFromFile("../Textures/skeletonChar.png");
    ghostTexture.loadFromFile("../Textures/ghost.png");

    auto rabbit = EnemiesFactory.Create(type::RABBIT, &rabbitTexture, sf::Vector2u(6, 4), 0.1f, 50.0f);
    auto skeleton = EnemiesFactory.Create(type::SKELETON, &skeletonTexture, sf::Vector2u(9, 4), 0.1f, 150.0f);
    auto ghost = EnemiesFactory.Create(type::GHOST, &ghostTexture, sf::Vector2u(3, 4), 0.1f, 200.f);




    //ELEMENTS
    std::vector<Element*> elements;

    elements.push_back(new Element(175, 175, "../Textures/tesoro-b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 1b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 2b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 3b.png", 0.3, 0.3));

    sf::RectangleShape platform;
    platform.setSize(sf::Vector2f(window.getSize().x, 100));
    platform.setPosition(0, -100);

    //if(player.playerBorder.getGlobalBounds().intersects(coins[i]->coinBorder.getGlobalBounds())){
   /* if(player->playerBorder.getGlobalBounds().intersects(rabbit->playerBorder.getGlobalBounds())){

    }

            }
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
        view.setCenter(player->body.getPosition());

        window.setView(view);

        map1.showMaps(window);
        map2.showMaps(window);




        //ELEMENTS

        for(auto element:elements){
            element->Draw(window);
        }

        window.draw(platform);




        //PLAYER

        player->Create(deltaTime, window);


        //ENEMIES
        rabbit->Create(deltaTime, window);
        skeleton->Create(deltaTime, window);
        ghost->Create(deltaTime, window);

        //Collisions
        //player Collision
        player->GetCollider().CheckCollision(ghost->GetCollider(), 0.5f);
        player->GetCollider().CheckCollision(rabbit->GetCollider(), 0.5f);
        player->GetCollider().CheckCollision(skeleton->GetCollider(), 0.5f);

        //ghost Collisions
        ghost->GetCollider().CheckCollision(player->GetCollider(), 0.5f);
        ghost->GetCollider().CheckCollision(rabbit->GetCollider(), 0.5f);
        ghost->GetCollider().CheckCollision(skeleton->GetCollider(), 0.5f);

        //skeleton Collisions
        skeleton->GetCollider().CheckCollision(player->GetCollider(), 0.5f);
        skeleton->GetCollider().CheckCollision(ghost->GetCollider(), 0.5f);
        skeleton->GetCollider().CheckCollision(rabbit->GetCollider(), 0.5f);

        //rabbit Collisions
        rabbit->GetCollider().CheckCollision(player->GetCollider(), 0.5f);
        rabbit->GetCollider().CheckCollision(ghost->GetCollider(), 0.5f);
        rabbit->GetCollider().CheckCollision(skeleton->GetCollider(), 0.5f);

        //Platforms, for collisions;


        window.display();
    }

    return 0;
}


