//
// Created by frangio on 24/05/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_GAMESTATE_H
#define THEBINDINGOFZELDAPROJECT_GAMESTATE_H

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
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "DEFINITIONS.h"
#include "NextLevel.h"


class GameState : public State
{
public:
    GameState(GameDataRef data);

    void Init() override;
    void charInit();
    void charGame(float dt);

    void HandleInput() override;
    void Update(float dt) override;
    void Draw(float dt) override;

private:

    GameDataRef _data;

    CharacterFactory characterFactory;
    ObserverReward CheckRoom;
    HUD hud;

    sf::View view;
    sf::View viewHUD;

    //AUDIO
    sf::SoundBuffer blast;
    sf::Sound laser;


    //MAP
    TileMap map;

    //CHARACTERS
    std::list<std::unique_ptr<Character>> characterList;
    Character* player;

    //OTHER VARIABLES


    std::vector<Bullet> BulletVecEnemy;
    bool deathPlayer;
    bool deathCharacter;


    //ELEMENTS
    std::vector<Element*> elements;                                         //Vector of elements

};



#endif //THEBINDINGOFZELDAPROJECT_GAMESTATE_H
