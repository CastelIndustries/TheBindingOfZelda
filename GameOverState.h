//
// Created by frangio on 27/05/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_GAMEOVERSTATE_H
#define THEBINDINGOFZELDAPROJECT_GAMEOVERSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"


class GameOverState : public State
{
public:
    GameOverState(GameDataRef data);

    void storeScore();

    void Init() override;
    void HandleInput() override;
    void Update(float dt) override;
    void Draw(float dt) override;

private:
    GameDataRef _data;

    sf::Clock _clock;

    sf::Text gameOverTexts[3];

    sf::View _view;

    int score;


};


#endif //THEBINDINGOFZELDAPROJECT_GAMEOVERSTATE_H
