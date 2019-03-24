#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <list>
#include "Animation.h"
#include "Player.h"
#include "Maps.h"
#include "Element.h"
#include "Wall.h"
#include "CharacterFactory.h"
#include "TileMap.h"
#include "ObserverReward.h"
#include <ctime>

int main() {
    //WINDOW
    sf::RenderWindow window(sf::VideoMode(1211, 865), "The Binding of Zelda", sf::Style::Close);
    srand((unsigned) time(nullptr));
    sf::View view(sf::Vector2f(336.0f, 336.0f), sf::Vector2f(1211, 865));

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

    characterList.push_back(characterFactory.Create(type::PLAYER, &playerTexture, sf::Vector2u(3, 4), 0.1f, 200.0f));
    characterList.push_back(characterFactory.Create(type::RABBIT, &rabbitTexture, sf::Vector2u(6, 4), 0.1f, 200.0f));
    characterList.push_back(characterFactory.Create(type::SKELETON, &skeletonTexture, sf::Vector2u(3, 4), 0.2f, 200.0f));
    characterList.push_back(characterFactory.Create(type::GHOST, &ghostTexture, sf::Vector2u(3, 4), 0.1f, 200.f));
    auto player = characterList.begin()->get();
    ObserverReward CheckRoom;
    player->RegisterObserver(&CheckRoom);





    //ELEMENTS
    std::vector<Element*> elements;

    elements.push_back(new Element(175, 175, "../Textures/tesoro-b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 1b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 2b.png", 0.3, 0.3));
    elements.push_back(new Element(175, 130, "../Textures/skeleton 3b.png", 0.3, 0.3));

    sf::Font font;
    if(!font.loadFromFile("../Textures/ARCADECLASSIC.TTF")){
        std::cout << "Error loading file" << std::endl;
        system("PAUSE");
    }



    float deltaTime;

    sf::Clock clock;

    // define the level with an array of tile indices
    const int level[] =
            {
                    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
            };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("../Textures/tileset2.png", level, 16, 8))
        return -1;

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
        window.draw(map);

        //ELEMENTS

        for(auto element:elements){
            element->Draw(window);
        }

        //window.draw(platform);

        //CHARACTERS
        bool deathCharacter = false;
        for(auto& character : characterList){


                character->Create(deltaTime, window);


            for(auto& otherCharacter : characterList){//Collision with other characters

                character->GetCollider().CheckCollision(otherCharacter->GetCollider(), 0.5f);
                for(int i=0; i<BulletVecPlayer.size();i++){                                     //Collision with bullets
                    if(BulletVecPlayer[i].CheckCollision(character->body) && character.get()!= player){
                         BulletVecPlayer[i]=BulletVecPlayer.back();
                         BulletVecPlayer.pop_back();
                         character->hp-=BulletVecPlayer[i].damage;
                    }
                    if (character->hp==0) {
                        player->kills++;
                        characterList.remove(character);
                        auto tmp_ptr = character.release();
                        delete tmp_ptr;
                        deathCharacter=true;
                        break;
                    }
                    }


                if(deathCharacter)
                    break;


            }
            if(deathCharacter)
                break;

            //PLAYER'S SHOOTING
            player->RangedAttack();
            if(player->isFiring){
                Bullet newBullet(sf::Vector2f(25,25),player->dirRanAtt);
                newBullet.setPos(sf::Vector2f(player->body.getPosition().x + player->body.getSize().x/2,player->body.getPosition().y + player->body.getSize().y/2));
                BulletVecPlayer.push_back(newBullet);
                player->isFiring=false;
            }

            for(int i =0;i<BulletVecPlayer.size();i++){
                BulletVecPlayer[i].Draw(window);
                BulletVecPlayer[i].fire(3.f);

            }
            player->NotifyObservers();
        }

        window.display();
    }
    player->RemoveObserver(&CheckRoom);
    return 0;
}


