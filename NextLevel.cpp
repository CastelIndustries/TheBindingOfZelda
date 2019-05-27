//
// Created by frangio on 24/05/19.
//


#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"
#include "NextLevel.h"
#include "MainMenuState.h"


#include <iostream>


NextLevel::NextLevel(GameDataRef data) : _data(data)
{

}

void NextLevel::Init()
{

    this->_data->levelCount ++;

    this->_data->assets.LoadFont("Font", FONT);

    this->level[0].setFont(this->_data->assets.GetFont("Font"));

    this->level[0].setOrigin(this->level[0].getGlobalBounds().width / 2.0f, this->level[0].getGlobalBounds().height / 2.0f  );

    this->level[0].setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f , SCREEN_HEIGHT/2.0f));

    this->level[0].setString("LEVEL " + std::to_string(this->_data->levelCount));


    this->level[1].setFont(this->_data->assets.GetFont("Font"));

    this->level[1].setOrigin(this->level[1].getGlobalBounds().width / 2.0f, this->level[1].getGlobalBounds().height / 2.0f  );

    this->level[1].setPosition(sf::Vector2f(SCREEN_WIDTH / 3.0f , SCREEN_HEIGHT/2.0f));

    this->level[1].setString("Use WASD to move. Use arrows to shoot. \n\n            ESC to pause.");

    this->level[1].setScale(0.5f, 0.5f);

    this->_view.setSize(SCREEN_WIDTH , SCREEN_HEIGHT);

    this->_clockIns.restart();

    this->_clockLvl.restart();

}

void NextLevel::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        switch(event.type) {

            case sf::Event::Closed:
                this->_data->window.close();
                break;


        }
    }
}

void NextLevel::Update(float dt)
{
    double time = NEXT_LEVEL_TIME;
    if(this->_data->levelCount == 1)
        time = NEXT_LEVEL_TIME + 3;

    if (this->_clockLvl.getElapsedTime().asSeconds() > time)
    {
        this->_data->machine.AddState(StateRef(new GameState(_data)), true);
    }

}

void NextLevel::Draw(float dt)
{

    this->_data->window.clear();

    this->_view.setCenter(sf::Vector2f((SCREEN_WIDTH + this->level[0].getGlobalBounds().width) /2.0f, SCREEN_HEIGHT/2.0f));

    this->_data->window.setView(this->_view);

    if(this->_data->levelCount == 1){
        this->_data->window.draw(this->level[1]);
        if(this->_clockIns.getElapsedTime().asSeconds() > INSTRUCTIONS_TIME) {
            this->_data->window.clear();
            this->_data->window.draw(this->level[0]);
        }
    }else
        this->_data->window.draw(this->level[0]);



    this->_data->window.display();

}
