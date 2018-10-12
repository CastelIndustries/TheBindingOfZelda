#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Animation.h"
#include "Player.h"
#include "Coin.h"
#include "Maps.h"
#include "Element.h"
#include "RangedCharacterFactory.h"
#include "MeleeCharacterFactory.h"
#include <ctime>

int main() {
    //WINDOW
    sf::RenderWindow window(sf::VideoMode(1211, 865), "Legend of Zelda", sf::Style::Close);
    srand((unsigned) time(nullptr));
    Maps map1;
    Maps map2;
    Maps map3;


    //PLAYERS
    RangedCharacterFactory PlayerFactory;
    sf::Texture playerTexture;
    playerTexture.loadFromFile("../Textures/FRANCO DEFINITIVO.png");

    //PLATFORMS, for collisions
    /* Platform platform1(nullptr,sf::Vector2f(300.0f,300.0f),sf::Vector2f(600.0f,400.0f));
     Platform platform2(nullptr,sf::Vector2f(300.0f,300.0f),sf::Vector2f(400.0f,500.0f));*/

    //Player player(&playerTexture, sf::Vector2u(12, 8), 0.035f, 150.0f);
    auto player = PlayerFactory.Create("player", &playerTexture, sf::Vector2u(3, 4), 0.10f, 200.0f);


    //ENEMIES
    MeleeCharacterFactory RabbitFactory;
    RangedCharacterFactory SkeletonFactory;
    RangedCharacterFactory GhostFactory;

    sf::Texture rabbitTexture;
    sf::Texture skeletonTexture;
    sf::Texture ghostTexture;

    rabbitTexture.loadFromFile("../Textures/rabbit.png");
    skeletonTexture.loadFromFile("../Textures/skeletonChar.png");
    ghostTexture.loadFromFile("../Textures/ghost.png");

    auto rabbit = RabbitFactory.Create("KungFu Rabbit", &rabbitTexture, sf::Vector2u(6, 4), 0.1f, 50.0f);
    auto skeleton = SkeletonFactory.Create("Skeleton", &skeletonTexture, sf::Vector2u(9, 4), 0.1f, 150.0f);
    auto ghost = GhostFactory.Create("ghost", &ghostTexture, sf::Vector2u(3 , 4), 0.1f, 200.f);

    //Characters Vectors





    //ELEMENTS
    std::vector<Element*> elements;

    elements.push_back(new Element(175, 175, "../Textures/tesoro-b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 1b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 2b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 3b.png", 0.3, 0.3));


        /*(int i=0; i<elements.size(); i++){
            for (int j = 0; j <elements.size(); ++j) {
                if(elements[i]->elementBorder.getGlobalBounds().intersects(elements[j]->elementBorder.getGlobalBounds())) {
                    elements[i]->elementBorder.setPosition(
                            rand() % (window.getSize().x - (int) elements[i]->elementBorder.getPosition().x),
                            rand() % (window.getSize().y - (int) elements[i]->elementBorder.getPosition().y));

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
        map1.showMaps(window);
        //window.setView(view);
        //ELEMENTS

        for(auto element:elements){
            element->Draw(window);
        }


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

        /*
        //PICKING COINS
        for(int i=0; i<nCoin; i++){
            if(player.playerBorder.getGlobalBounds().intersects(coins[i]->coinBorder.getGlobalBounds())){
                coins.erase(coins.begin() + i);
                nCoin--;
                count++;
                coinSound.play();
            }
        }
        pickedCoins.setString("COINS : "+ std::to_string(count));
        window.draw(pickedCoins);
*/

        window.display();
    }

    return 0;
}


