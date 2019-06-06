//
// Created by frangio on 23/05/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_GAME_H
#define THEBINDINGOFZELDAPROJECT_GAME_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

struct GameData
{
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
    sf::Sound soundtrack;
    int levelCount, Lives, preMap, totalKills,  numEnemies, highScore;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
    Game(int width, int height, std::string title);


private:

    float dt;
    sf::SoundBuffer song;
    sf::Clock _clock;

    GameDataRef _data = std::make_shared<GameData>();

    void Run();
};



#endif //THEBINDINGOFZELDAPROJECT_GAME_H
