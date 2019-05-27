//
// Created by frangio on 23/05/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_SPLASHSTATE_H
#define THEBINDINGOFZELDAPROJECT_SPLASHSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class SplashState : public State
{
public:
    SplashState(GameDataRef data);

    void Init() override;

    void HandleInput() override;
    void Update(float dt) override;
    void Draw(float dt) override;

private:
    GameDataRef _data;

    sf::Clock _clock;

    sf::Text title[1];
};


#endif //THEBINDINGOFZELDAPROJECT_SPLASHSTATE_H
