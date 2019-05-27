#include <utility>

//
// Created by frangio on 23/05/19.
//

#include "MainMenuState.h"
#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"

#include <iostream>


MainMenuState::MainMenuState(GameDataRef data) : _data(std::move(data))
{

}

void MainMenuState::Init() {
    this->_data->window.clear();

    this->_data->levelCount = 0;

    this->_data->totalKills = 0;

    this->_data->numEnemies = 3;

    this->_data->Lives = 3;

    this->_data->assets.LoadFont("Text Font", FONT);

    this->menu[0].setFont(this->_data->assets.GetFont("Text Font"));
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("PLAY");
    menu[0].setOrigin(menu[0].getGlobalBounds().width / 2, menu[0].getGlobalBounds().height / 2);
    menu[0].setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 2));
    menu[0].setScale(2.0f, 2.0f);

    menu[1].setFont(this->_data->assets.GetFont("Text Font"));
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("EXIT");
    menu[1].setOrigin(menu[1].getGlobalBounds().width / 2, menu[1].getGlobalBounds().height / 2);
    menu[1].setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 3));
    menu[1].setScale(2.0f, 2.0f);

    selectedItemIndex = 0;

    texts[0].setFont(this->_data->assets.GetFont("Text Font"));
    texts[0].setString("Use arrows to navigate. Press ENTER to confirm.");
    texts[0].setScale(0.5f, 0.5f);
    texts[0].setOrigin(texts[1].getGlobalBounds().width, texts[1].getGlobalBounds().height);
    texts[0].setPosition(sf::Vector2f((SCREEN_WIDTH - texts[0].getGlobalBounds().width) / 2.0f, SCREEN_HEIGHT - 20));

    this->_view.setSize(SCREEN_WIDTH , SCREEN_HEIGHT);

    conf.loadFromFile(CONFIRM_AUDIO);
    sel.loadFromFile(SELECTION_AUDIO);

    selection.setBuffer(sel);
    confirm.setBuffer(conf);

    selection.setVolume(10.0f);
    confirm.setVolume(10.0f);
}

void MainMenuState::HandleInput()
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
                                confirm.play();
                                this->_data->soundtrack.play();
                                this->_data->machine.AddState(StateRef(new NextLevel(_data)), true);
                                break;
                            case 1:
                                confirm.play();
                                this->_data->window.close();
                                break;
                        }

                }

        }

        if(this->_data->input.IsTextSelectioned(this->menu[0], this->_data->window)){
            MoveUp();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                confirm.play();
                this->_data->soundtrack.play();
                this->_data->machine.AddState(StateRef(new NextLevel(_data)), true);
            }
        }
        if(this->_data->input.IsTextSelectioned(this->menu[1], this->_data->window)){
            MoveDown();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                confirm.play();
                this->_data->window.close();
            }
        }
    }
}

void MainMenuState::Update(float dt)
{

}

void MainMenuState::Draw(float dt)
{

    this->_data->window.clear();

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS -2 ; i++) {
        this->_data->window.draw(this->menu[i]);
    }


    this->_data->window.draw(this->texts[0]);

    this->_view.setCenter(sf::Vector2f(SCREEN_WIDTH /2.0f, SCREEN_HEIGHT/2.0f));

    this->_data->window.setView(this->_view);

    this->_data->window.display();
}

void MainMenuState::MoveUp() {
    if (selectedItemIndex - 1 >= 0)
    {
        this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        this->selectedItemIndex--;
        this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void MainMenuState::MoveDown() {
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS -2 )
    {
        this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        this->selectedItemIndex++;
        this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}