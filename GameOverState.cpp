//
// Created by frangio on 23/05/19.
//

#include <sstream>
#include "GameOverState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"

#include <iostream>


GameOverState::GameOverState(GameDataRef data) : _data(data)
{

}

void GameOverState::Init()
{

    this->_data->soundtrack.stop();

    this->_data->assets.LoadFont("Font", FONT);

    this->death[0].setFont(this->_data->assets.GetFont("Font"));

    this->death[0].setOrigin(this->death[0].getGlobalBounds().width / 2.0f, this->death[0].getGlobalBounds().height / 2.0f  );

    this->death[0].setPosition(sf::Vector2f(SCREEN_WIDTH/4.0f , SCREEN_HEIGHT/2.0f));

    this->death[0].setString("YOU DIED");

    this->death[1].setFont(this->_data->assets.GetFont("Font"));

    this->death[1].setOrigin(this->death[1].getGlobalBounds().width / 2.0f, this->death[1].getGlobalBounds().height / 2.0f  );

    this->death[1].setPosition(sf::Vector2f(this->death[0].getPosition().x , this->death[0].getPosition().y + 100));

    this->death[1].setString("SCORE: " + std::to_string(this->_data->totalKills));

    this->_view.setSize(SCREEN_WIDTH , SCREEN_HEIGHT);

    this->_clock.restart();

}

void GameOverState::HandleInput()
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

void GameOverState::Update(float dt)
{
    if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
    {
        // Switch To Main Menu

        this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
    }
}

void GameOverState::Draw(float dt)
{
    this->_data->window.clear();

    this->_data->window.draw( this->death[0]);

    this->_data->window.draw(this->death[1]);

    this->_view.setCenter(sf::Vector2f(SCREEN_WIDTH /3.0f, SCREEN_HEIGHT/2.0f));

    this->_data->window.setView(this->_view);

    this->_data->window.display();
}
