#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <ctime>
#include <sstream>
#include "Animation.h"
#include "Player.h"
#include "Element.h"
#include "CharacterFactory.h"
#include "TileMap.h"
#include "ObserverReward.h"

#include "HUD.h"


int main() {
    //WINDOW AND MENU
    sf::RenderWindow window(sf::VideoMode(1211, 865), "The Binding of Zelda", sf::Style::Close);
    srand((unsigned) time(nullptr));




    //PLAYERS
    CharacterFactory PlayerFactory;
    sf::Texture playerTexture;
    playerTexture.loadFromFile("../Textures/FRANCO DEFINITIVO.png");
    std::vector<Bullet> BulletVecPlayer;

    //ENEMIES
    CharacterFactory characterFactory;

    sf::Texture rabbitTexture;
    sf::Texture skeletonTexture;
    sf::Texture ghostTexture;

    rabbitTexture.loadFromFile("../Textures/rabbit.png");
    skeletonTexture.loadFromFile("../Textures/skeleton.png");
    ghostTexture.loadFromFile("../Textures/ghost.png");

    std::list<std::unique_ptr<Character>> characterList;

    characterList.push_back(characterFactory.Create(type::PLAYER, &playerTexture, sf::Vector2u(3, 4), 0.1f, 300.0f));
    characterList.push_back(characterFactory.Create(type::RABBIT, &rabbitTexture, sf::Vector2u(6, 4), 0.1f, 200.0f));
    characterList.push_back(characterFactory.Create(type::SKELETON, &skeletonTexture, sf::Vector2u(3, 4), 0.2f, 200.0f));
    characterList.push_back(characterFactory.Create(type::GHOST, &ghostTexture, sf::Vector2u(3, 4), 0.1f, 200.f));
    auto player = characterList.begin()->get();

    ObserverReward CheckRoom;
    player->RegisterObserver(&CheckRoom);

    sf::View view(player->body.getPosition(), sf::Vector2f(1211, 865));
    view.zoom(4.0f);
    sf::View viewHUD(player->body.getPosition(), sf::Vector2f(1211, 865));

    //ELEMENTS

    HUD hud;

    std::vector<Element *> elements;

    elements.push_back(new Element(175, 175, "../Textures/tesoro-b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 1b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 2b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 3b.png", 0.3, 0.3));

    float deltaTime;

    sf::Clock clock;

    // create the tilemap from the level definition
    TileMap map;

    map.LoadColMap("../Textures/Map.txt");
    if (!map.load("../Textures/tileset3.png", 71, 36, window))
        return -1;
    //TESTER


    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();


        sf::Event evnt;
        while (window.pollEvent(evnt)) {

            switch (evnt.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

            }


        }
        //WINDOW
        window.clear();

        view.setCenter(player->body.getPosition());

        window.setView(view);

        window.draw(map);
        map.drawColTile(window);

        viewHUD.setCenter(player->body.getPosition());
        viewHUD.setViewport(sf::FloatRect(1.0f, 1.0f, 1.0f, 1.0f));
        hud.renderHUD(viewHUD, window, player);

        //ELEMENTS

        /*for(auto element:elements){
            element->Draw(window);
        }*/



        //CHARACTERS



        bool deathCharacter = false;
        for (auto &character : characterList) {
            character->Create(deltaTime, window);
            if (character.get() != player) {
                character->ArtificialIntelligence(*player, 0.1f, window);
            }
            map.checkCollision(characterList, player);

            for (auto &otherCharacter : characterList) {//Collision with other characters

                character->GetCollider().CheckCollision(otherCharacter->GetCollider(), 0.5f);
                if (otherCharacter.get() != player)


                    for (int i = 0;
                         i < BulletVecPlayer.size(); i++) {                                     //Collision with bullets
                        if (BulletVecPlayer[i].CheckCollision(character->body) && character.get() != player) {
                            BulletVecPlayer[i] = BulletVecPlayer.back();
                            BulletVecPlayer.pop_back();
                            character->hp -= BulletVecPlayer[i].damage;
                        }

                        if (character->hp == 0) {
                            player->kills++;
                            player->totalKills++;
                            characterList.remove(character);
                            auto tmp_ptr = character.release();
                            delete tmp_ptr;
                            deathCharacter = true;
                            break;
                        }
                    }


                if (deathCharacter)
                    break;


            }
            if (deathCharacter)
                break;

            //PLAYER'S SHOOTING
            player->RangedAttack();
            if (player->isFiring) {
                Bullet newBullet(sf::Vector2f(30, 30), player->dirRanAtt);
                newBullet.setPos(sf::Vector2f(player->body.getPosition().x + player->body.getSize().x / 2,
                                              player->body.getPosition().y + player->body.getSize().y / 2));
                BulletVecPlayer.push_back(newBullet);
                player->isFiring = false;
            }

            for (int i = 0; i < BulletVecPlayer.size(); i++) {
                BulletVecPlayer[i].Draw(window);
                BulletVecPlayer[i].fire(9.f);

            }

            player->NotifyObservers(map, window);

            if (character->isFiring) {
                Bullet newBullet(sf::Vector2f(30, 30), character->dirRanAtt);
                newBullet.setPos(sf::Vector2f(character->body.getPosition().x + character->body.getSize().x / 2,
                                              character->body.getPosition().y + character->body.getSize().y / 2));
                character->BulletVec.push_back(newBullet);
                character->isFiring = false;
            }
            for (int i = 0; i < character->BulletVec.size(); i++) {
                character->BulletVec[i].Draw(window);
                character->BulletVec[i].fire(9.f);

            }

        }

        window.display();

        player->RemoveObserver(&CheckRoom);
    }
    // }

    return 0;
}


