//
// Created by frangio on 23/05/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_MAINMENUSTATE_H
#define THEBINDINGOFZELDAPROJECT_MAINMENUSTATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

class MainMenuState : public State
{
public:
    MainMenuState(GameDataRef data);

    void Init() override;

    void HandleInput() override;
    void MoveUp();
    void MoveDown();
    void Update(float dt) override;
    void Draw(float dt) override;
    int GetPressedItem() { return selectedItemIndex; }

private:
    GameDataRef _data;

    int selectedItemIndex;
    sf::Text texts[MAX_NUMBER_OF_ITEMS];
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

    sf::View _view;



    sf::SoundBuffer sel;
    sf::SoundBuffer conf;

    sf::Sound selection;
    sf::Sound confirm;

};


#endif //THEBINDINGOFZELDAPROJECT_MAINMENUSTATE_H
