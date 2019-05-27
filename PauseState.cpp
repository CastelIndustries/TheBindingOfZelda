//
// Created by frangio on 27/05/19.
//

#include "PauseState.h"
#include "MainMenuState.h"
#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"

#include <iostream>


PauseState::PauseState(GameDataRef data) : _data(std::move(data))
{

}

void PauseState::Init()
{
    this->_data->window.clear();

    this->_data->assets.LoadFont("Text Font", FONT);

    this->pause[0].setFont(this->_data->assets.GetFont("Text Font"));
    pause[0].setFillColor(sf::Color::Red);
    pause[0].setString("RESUME");
    pause[0].setOrigin(pause[0].getGlobalBounds().width/2, pause[0].getGlobalBounds().height/2);
    pause[0].setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1)*2));
    pause[0].setScale(2.0f, 2.0f);

    pause[1].setFont(this->_data->assets.GetFont("Text Font"));
    pause[1].setFillColor(sf::Color::White);
    pause[1].setString("MENU");
    pause[1].setOrigin(pause[1].getGlobalBounds().width/2, pause[1].getGlobalBounds().height/2);
    pause[1].setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 3));
    pause[1].setScale(2.0f, 2.0f);

    selectedItemIndex = 0;

    conf.loadFromFile(CONFIRM_AUDIO);
    sel.loadFromFile(SELECTION_AUDIO);

    selection.setBuffer(sel);

    confirm.setBuffer(conf);

    selection.setVolume(10.0f);
    confirm.setVolume(10.0f);

    this->_data->soundtrack.pause();

    this->_view.setSize(SCREEN_WIDTH , SCREEN_HEIGHT);
}

void PauseState::HandleInput()
{
    float dt = 0;
    sf::Event event;

    while (this->_data->window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->_data->window.close();
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        MoveUp();
                        selection.play();
                        break;
                    case sf::Keyboard::Down:
                        MoveDown();
                        selection.play();
                        break;
                    case sf::Keyboard::Return:
                        confirm.play();
                        switch (this->GetPressedItem()) {
                            case 0:
                                this->_data->machine.RemoveState();
                                this->_data->soundtrack.play();
                                break;
                            case 1:
                                this->_data->soundtrack.stop();
                                this->_data->machine.RemoveState();
                                this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
                                break;
                        }
                }

        }

        if(this->_data->input.IsTextSelectioned(this->pause[0], this->_data->window)){
            MoveUp();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                confirm.play();
                this->_data->soundtrack.play();
                this->_data->machine.RemoveState();
            }
        }
        if(this->_data->input.IsTextSelectioned(this->pause[1], this->_data->window)){
            MoveDown();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                confirm.play();
                this->_data->soundtrack.stop();
                this->_data->machine.RemoveState();
                this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);

            }
        }
    }
}

void PauseState::Update(float dt)
{

}

void PauseState::Draw(float dt)
{
    this->_data->window.clear();

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS -2; i++) {
        this->_data->window.draw(this->pause[i]);
    }

    this->_view.setCenter(sf::Vector2f(SCREEN_WIDTH /2.0f, SCREEN_HEIGHT/2.0f));

    this->_data->window.setView(this->_view);

    this->_data->window.display();
}

void PauseState::MoveUp() {
    if (selectedItemIndex - 1 >= 0)
    {
        this->pause[selectedItemIndex].setFillColor(sf::Color::White);
        this->selectedItemIndex--;
        this->pause[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void PauseState::MoveDown() {
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS - 2 )
    {
        this->pause[selectedItemIndex].setFillColor(sf::Color::White);
        this->selectedItemIndex++;
        this->pause[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}