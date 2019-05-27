#include <utility>

//
// Created by frangio on 24/05/19.
//

#include "GameState.h"



#include <sstream>
#include "GameState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"
#include "PauseState.h"
#include "GameOverState.h"
//#include "PauseState.h"
//#include "GameOverState.h"

#include <iostream>
GameState::GameState(GameDataRef data) : _data(std::move(data))
{

}

void GameState::Init()
{


    this->_data->window.clear();

    srand((unsigned) time(nullptr));

    //VIEWS
    view.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    view.zoom(4.0f);
    viewHUD.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    viewHUD.setViewport(sf::FloatRect(1.0f, 1.0f, 1.0f, 1.0f));

    //MAP
    map.InitMap(MAP_WIDTH, MAP_HEIGHT, TILE_SIZE);

    map.LoadColMap(this->_data->preMap);

    if (!(map.load(TILE_SET_TEXTURE, this->_data->window), true))
        std::cout<<"ERROR TILE_SET_TEXTURE"<<std::endl;

    //CHARACTERS
    characterList.push_back(characterFactory.Create(type::PLAYER , PLAYER_TEXTURE , PLAYER_IMAGE_COUNT , PLAYER_SWITCH_TIME , PLAYER_SPEED));

    for (int i = 0; i < this->_data->numEnemies ; i++) {
        int j = rand() % 3;
        switch (j) {
            case 0:
                characterList.push_back(
                        characterFactory.Create(type::SKELETON, SKELETON_TEXTURE, SKELETON_IMAGE_COUNT, SKELETON_SWITCH_TIME,
                                                SKELETON_SPEED));
                break;
            case 1:
                characterList.push_back(
                        characterFactory.Create(type::GHOST, GHOST_TEXTURE, GHOST_IMAGE_COUNT,
                                                GHOST_SWITCH_TIME, GHOST_SPEED));
                break;
            case 2:
                characterList.push_back(
                        characterFactory.Create(type::RABBIT, RABBIT_TEXTURE, RABBIT_IMAGE_COUNT, RABBIT_SWITCH_TIME,
                                                RABBIT_SPEED));
                break;
        }

    }

    //calling first element of the list PLAYER to understand better
    player = characterList.begin()->get();

    //OBSERVER
    for(auto &characterObs : characterList){                                //Register every character to observer
        characterObs->RegisterObserver(&this->CheckRoom);
    }

    //SOUNDS

    blast.loadFromFile(BLAST_AUDIO);

    laser.setBuffer(blast);

    laser.setVolume(10.0f);

    //ELEMENTS
    elements.push_back(new Element(175, 175, CHEST_TEXTURE , 0.5, 0.5));
    elements.push_back(new Element(175, 130, BONE_1_TEXTURE, 0.5, 0.5));
    elements.push_back(new Element(175, 130, BONE_2_TEXTURE, 0.5, 0.5));
    elements.push_back(new Element(175, 130, BONE_3_TEXTURE, 0.5, 0.5));

}

void GameState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }

        if(sf::Event::KeyReleased == event.type){
            if(sf::Keyboard::Escape == event.key.code)
                this->_data->machine.AddState(StateRef( new PauseState(_data)), false);
        }
    }

}


void GameState::Update(float dt) {
    charInit();
}

void GameState::Draw(float dt) {
    this->_data->window.clear();

    //VIEW
    view.setCenter(player->body.getPosition());
    viewHUD.setCenter(player->body.getPosition());
    this->_data->window.setView(view);


    this->_data->window.draw(this->map);
    map.drawColTile(this->_data->window);

    for (auto element:elements){
        element->Draw(this->_data->window);
    }
    for(auto &character : characterList)
        character->Create(dt, this->_data->window);

    //HUD
    hud.renderHUD(viewHUD, this->_data->window, player, this->_data->Lives);

    charGame(dt);

    this->_data->window.display();
}

void GameState::charInit() {


    //CHARACTERS
    for (auto &character : characterList) {

        map.checkCollision(characterList, player);

        for (auto &otherCharacter : characterList) {                    //Collision with other characters

            character->GetCollider().CheckCollision(otherCharacter->GetCollider(), 0.5f);
        }
    }

}


void GameState::charGame(float dt) {

    deathPlayer = false;
    deathCharacter = false;
    player->RangedAttack();
    if(!characterList.empty()) {
        for (auto &character : characterList) {
            if (character.get() != player) {
                character->ArtificialIntelligence(*player, dt, this->_data->window);
            }

            if (character->isFiring) {
                Bullet newBullet("../Resources/res/bullet.png", sf::Vector2f(30, 30), character->dirRanAtt);
                if (character.get() == player) {
                    newBullet.setSize(sf::Vector2f(30, 30));
                    laser.play();
                } else {
                    newBullet.setSize(sf::Vector2f(80, 80));
                    newBullet.damage = 34;
                }

                newBullet.setPos(sf::Vector2f(character->body.getPosition().x + character->body.getSize().x / 2,
                                              character->body.getPosition().y + character->body.getSize().y / 2));

                character->BulletVec.push_back(newBullet);
                character->isFiring = false;
            }

            for (int i = 0; i < character->BulletVec.size(); i++) {
                character->BulletVec[i].Draw(this->_data->window);
                if (character.get() != player)
                    character->BulletVec[i].fire(20.f);
                else
                    character->BulletVec[i].fire(50.0f);
            }


            for (int i = 0; i <
                            player->BulletVec.size(); i++) {                                                     //Collision with bullets
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
                    this->_data->totalKills++;
                    characterList.remove(character);
                    auto tmp_ptr = character.release();
                    delete tmp_ptr;
                    deathCharacter = true;
                    break;
                }

            }

            if (deathCharacter)
                break;

            if (character.get() != player) {
                for (int i = 0; i <
                                character->BulletVec.size(); i++) {                                                     //Collision with bullets
                    if (character->BulletVec[i].CheckCollision(player->body)) {
                        character->BulletVec[i] = character->BulletVec.back();
                        character->BulletVec.pop_back();
                        player->hp -= character->BulletVec[i].damage;
                        this->_data->Lives--;

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


            if (deathPlayer) {
                this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
                break;
            }


            character->NotifyObservers(this->_data, map,
                                       this->_data->window);                        //Notify observers for eventual updating
        }
    }
}
