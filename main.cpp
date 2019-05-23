#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <ctime>
#include <sstream>
#include <stdlib.h>
#include "Animation.h"
#include "Player.h"
#include "Element.h"
#include "CharacterFactory.h"
#include "TileMap.h"
#include "ObserverReward.h"
#include "HUD.h"
#include "Menu.h"
#include "GameOver.h"
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



int main() {

    srand((unsigned) time(nullptr));

    //WINDOW
    sf::RenderWindow window(sf::VideoMode(1211, 865), "The Binding of Zelda", sf::Style::Close);

    //CHARACTERS
    CharacterFactory characterFactory;

    //list
    std::list<std::unique_ptr<Character>> characterList;

    characterList.push_back(characterFactory.Create(type::PLAYER, "../Textures/FRANCO DEFINITIVO1.png", sf::Vector2u(3, 6), 0.1f, 600.0f));
    characterList.push_back(characterFactory.Create(type::RABBIT, "../Textures/rabbit.png", sf::Vector2u(6, 4), 0.1f, 200.0f));
    characterList.push_back(characterFactory.Create(type::SKELETON, "../Textures/skeleton.png", sf::Vector2u(3, 4), 0.5f, 200.0f));
    characterList.push_back(characterFactory.Create(type::GHOST, "../Textures/ghost.png", sf::Vector2u(2, 4), 0.3f, 200.f));

    auto player = characterList.begin()->get();                             //calling first element of the list PLAYER to understand better

    //OBSERVER
    ObserverReward CheckRoom;

    for(auto &characterObs : characterList){                                //Register every character to observer
        characterObs->RegisterObserver(&CheckRoom);
    }

    //VIEW
    sf::View view(player->body.getPosition(), sf::Vector2f(1211, 865));
    view.zoom(4.0f);

    //MENU
    Menu menu(window.getSize().x, window.getSize().y);
    GameOver over(window.getSize().x, window.getSize().y);

    //HUD
    HUD hud;
    sf::View viewHUD(player->body.getPosition(), sf::Vector2f(1211, 865));

    //ELEMENTS
    std::vector<Element*> elements;                                         //Vector of elements
    sf::Music soundtrack;
    if(!soundtrack.openFromFile("../Textures/song.ogg"))
        std::cout<<"ERROR"<<std::endl;


    //elements.push_back(new Element(538, 175, "../Textures/chiave.png", 0.5, 0.5));
    elements.push_back(new Element(175, 175, "../Textures/tesoro-b.png", 0.5, 0.5));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 1b.png", 0.5, 0.5));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 2b.png", 0.5, 0.5));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 3b.png", 0.5, 0.5));
    //auto key = elements[0];
    //key->SetPosition();



    //std::vector<Bullet> BulletVecPlayer;                                   //Vector for the bullets

    //MAP
    TileMap map(71, 36, sf::Vector2u(175, 175));

    map.LoadColMap();

    if (!map.load("../Textures/tileset3.png", window))
        return -1;


    //OTHER VARIABLES
    sf::Clock clock;
    float deltaTime;
    bool inMenu=true;
    int caseMenu=0;
    bool deathPlayer = false;
    int NumEnemies = 3;


    //WINDOW OPEN
    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt)) {

            switch (evnt.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyReleased:
                    if(inMenu) {                                                            //CONTROLS IN MENU
                        switch (evnt.key.code) {
                            case sf::Keyboard::Up:
                                menu.moveUp();
                                break;

                            case sf::Keyboard::Down:
                                menu.moveDown();
                                break;

                            case sf::Keyboard::Return:
                                switch (menu.GetPressedItem()) {
                                    case 0:
                                        if(menu.clock.getElapsedTime().asSeconds() > 1) {           //TIME FOR INSTRUCTIONS BEFORE GAME STARTS
                                            menu.clock.restart();
                                            soundtrack.play();
                                            caseMenu = 1;
                                            inMenu = false;
                                            break;
                                        }
                                        else
                                            break;
                                    case 1:
                                        inMenu = false;
                                        window.close();
                                        break;
                                }

                                break;
                        }
                    }
                    else
                        break;

                    break;
            }
        }
        window.clear();
        //MENU

        menu.draw(window);
        //PLAY SELECTED
        if(caseMenu==1) {
            window.clear();

            //INSTRUCTIONS
            if (menu.instructions(window)) {
                //GAME STARTS
                window.clear();

                //MAP
                window.draw(map);
                map.drawColTile(window);

                //VIEW FOR MAP
                view.setCenter(player->body.getPosition());
                viewHUD.setCenter(player->body.getPosition());

                viewHUD.setViewport(sf::FloatRect(1.0f, 1.0f, 1.0f, 1.0f));
                window.setView(view);

                //HUD


                //VIEW FOR HUD


                //ELEMENTS
                for (auto element:elements) {
                   //if(element != key)
                   element->Draw(window);
                }

                if (player->newCharacter) {
                    for (int i = 0; i < NumEnemies; i++) {
                        int j = rand() % 3;
                        switch (j) {
                            case 0:
                                characterList.push_back(
                                        characterFactory.Create(type::RABBIT, "../Textures/rabbit.png", sf::Vector2u(6, 4), 0.1f,
                                                                200.0f));
                                break;
                            case 1:
                                characterList.push_back(
                                        characterFactory.Create(type::SKELETON, "../Textures/skeleton.png", sf::Vector2u(3, 4),
                                                                0.5f, 200.0f));
                                break;
                            case 2:
                                characterList.push_back(
                                        characterFactory.Create(type::GHOST, "../Textures/ghost.png", sf::Vector2u(2, 4), 0.3f,
                                                                200.f));
                                break;
                        }

                    }
                    player->newCharacter = false;
                    //NumEnemies++;
                }

                //PLAYER'S ATTACK
                player->RangedAttack();


                //CHARACTERS
                bool deathCharacter = false;

                for (auto &character : characterList) {


                    character->Create(deltaTime, window);



                    map.checkCollision(characterList, player);

                    for (auto &otherCharacter : characterList) {                    //Collision with other characters

                        character->GetCollider().CheckCollision(otherCharacter->GetCollider(), 0.5f);
                    }

                    if(character.get() != player){

                        character->ArtificialIntelligence(*player, deltaTime, window);
                    }

                    if (character->isFiring) {
                        Bullet newBullet("../Textures/bullet.png", sf::Vector2f(30, 30), character->dirRanAtt);
                        if(character.get() == player) {
                            newBullet.setSize(sf::Vector2f(30, 30));
                        }
                        else {
                            newBullet.setSize(sf::Vector2f(80, 80));
                            newBullet.damage = 34;
                        }

                        newBullet.setPos(sf::Vector2f(character->body.getPosition().x + character->body.getSize().x / 2,
                                                      character->body.getPosition().y + character->body.getSize().y / 2));

                        character->BulletVec.push_back(newBullet);
                        character->isFiring = false;
                    }

                    for (int i = 0; i < character->BulletVec.size(); i++) {
                        character->BulletVec[i].Draw(window);
                        if(character.get() != player)
                            character->BulletVec[i].fire(20.f);
                        else
                            character->BulletVec[i].fire(50.0f);
                    }


                    for (int i = 0; i < player->BulletVec.size(); i++) {                                                     //Collision with bullets
                        if (player->BulletVec[i].CheckCollision(character->body) && character.get() != player) {
                            player->BulletVec[i] = player->BulletVec.back();
                            player->BulletVec.pop_back();
                            character->hp -= player->BulletVec[i].damage;

                        }
                        for (auto tiles:map.colTiles) {
                            if (player->BulletVec[i].CheckCollision(tiles->tile) && !tiles->getWalk()) {
                                player->BulletVec[i] = player->BulletVec.back();                                          //Collision bullet-walls
                                player->BulletVec.pop_back();
                            }
                        }
                        if (character->hp <= 0) {                                                                                                //Dead character
                            player->kills++;
                            player->l_kills++;
                            characterList.remove(character);
                            auto tmp_ptr = character.release();
                            delete tmp_ptr;
                            deathCharacter = true;
                            break;
                        }

                    }

                    if (deathCharacter)
                        break;

                    if(character.get() != player) {
                        for (int i = 0; i < character->BulletVec.size(); i++) {                                                     //Collision with bullets
                            if (character->BulletVec[i].CheckCollision(player->body)) {
                                character->BulletVec[i] = character->BulletVec.back();
                                character->BulletVec.pop_back();
                                player->hp -= character->BulletVec[i].damage;

                            }
                            for (auto tiles:map.colTiles) {
                                if (character->BulletVec[i].CheckCollision(tiles->tile) && !tiles->getWalk()) {
                                    character->BulletVec[i] = character->BulletVec.back();                                          //Collision bullet-walls
                                    character->BulletVec.pop_back();
                                }
                            }
                            deathPlayer = hud.lifePointRemove(player);
                        }
                    }


                    if (deathPlayer)
                        break;


                    character->NotifyObservers(map, window);                        //Notify observers for eventual updating
                }
                hud.renderHUD(viewHUD, window, player);
                if (deathPlayer) {
                    over.gameover(window);
                    break;
                }
            }


        }


        window.display();
    }


    player->RemoveObserver(&CheckRoom);
    return 0;
}