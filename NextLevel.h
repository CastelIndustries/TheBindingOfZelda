//
// Created by frangio on 24/05/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_NEXTLEVEL_H
#define THEBINDINGOFZELDAPROJECT_NEXTLEVEL_H


#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class NextLevel : public State
{
public:
    NextLevel(GameDataRef data);

    void Init() override;

    void HandleInput() override;
    void Update(float dt) override;
    void Draw(float dt) override;

private:
    GameDataRef _data;

    sf::Clock _clockIns;
    sf::Clock _clockLvl;

    sf::Text level[2];

    sf::View _view;

};



#endif //THEBINDINGOFZELDAPROJECT_NEXTLEVEL_H
