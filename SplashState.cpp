//
// Created by frangio on 23/05/19.
//

#include <sstream>
#include "SplashState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"

#include <iostream>


SplashState::SplashState(GameDataRef data) : _data(data)
{

}

void SplashState::Init()
{
    this->_data->assets.LoadFont("Font", FONT);

    this->title[0].setFont(this->_data->assets.GetFont("Font"));

    this->title[0].setOrigin(this->title[0].getGlobalBounds().width / 2.0f, this->title[0].getGlobalBounds().height / 2.0f  );

    this->title[0].setPosition(sf::Vector2f(SCREEN_WIDTH/4.0f , SCREEN_HEIGHT/2.0f));

    this->title[0].setString("THE BINDING OF ZELDA ");
}

void SplashState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }
    }
}

void SplashState::Update(float dt)
{
    if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
    {
        // Switch To Main Menu
        this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
    }
}

void SplashState::Draw(float dt)
{
    this->_data->window.clear();

    this->_data->window.draw( this->title[0] );

    this->_data->window.display();
}
