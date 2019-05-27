//
// Created by frangio on 23/05/19.
//

#include <iostream>
#include "Game.h"
#include "SplashState.h"
#include "DEFINITIONS.h"

Game::Game(int width, int height, std::string title)
{
    _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    _data->machine.AddState(StateRef(new SplashState(this->_data)));


    song.loadFromFile(SONG_AUDIO);
    _data->soundtrack.setBuffer(song);
    _data->soundtrack.setVolume(10.0f);

    this->Run();

}

void Game::Run()
{
    while (this->_data->window.isOpen())
    {
        this->_data->machine.ProcessStateChanges();


        dt = this->_clock.restart().asSeconds();

        this->_data->machine.GetActiveState()->HandleInput();
        this->_data->machine.GetActiveState()->Update(dt);
        this->_data->machine.GetActiveState()->Draw(dt);
    }
}

