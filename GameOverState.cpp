//
// Created by frangio on 23/05/19.
//

#include <sstream>
#include "GameOverState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"

#include <iostream>
#include <fstream>


GameOverState::GameOverState(GameDataRef data) : _data(data)
{

}

void GameOverState::Init()
{

    this->_data->soundtrack.stop();

    score = this->_data->totalKills;

    this->_data->assets.LoadFont("Font", FONT);

    this->gameOverTexts[0].setFont(this->_data->assets.GetFont("Font"));

    this->gameOverTexts[0].setOrigin(this->gameOverTexts[0].getGlobalBounds().width / 2.0f, this->gameOverTexts[0].getGlobalBounds().height / 2.0f  );

    this->gameOverTexts[0].setPosition(sf::Vector2f(SCREEN_WIDTH/4.0f , SCREEN_HEIGHT/2.0f));

    this->gameOverTexts[0].setString("YOU DIED");

    this->gameOverTexts[1].setFont(this->_data->assets.GetFont("Font"));

    this->gameOverTexts[1].setOrigin(this->gameOverTexts[1].getGlobalBounds().width / 2.0f, this->gameOverTexts[1].getGlobalBounds().height / 2.0f  );

    this->gameOverTexts[1].setPosition(sf::Vector2f(this->gameOverTexts[0].getPosition().x , this->gameOverTexts[0].getPosition().y + 100));


    this->gameOverTexts[2].setFont(this->_data->assets.GetFont("Font"));

    this->gameOverTexts[2].setOrigin(this->gameOverTexts[2].getGlobalBounds().width / 2.0f, this->gameOverTexts[2].getGlobalBounds().height / 2.0f  );

    this->gameOverTexts[2].setPosition(sf::Vector2f(this->gameOverTexts[0].getPosition().x , this->gameOverTexts[0].getPosition().y + 200));



    this->_view.setSize(SCREEN_WIDTH , SCREEN_HEIGHT);

    storeScore();

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

    this->gameOverTexts[1].setString("SCORE: " + std::to_string(score));

    this->gameOverTexts[2].setString("BEST: " + std::to_string(this->_data->highScore));

    if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
    {
        // Switch To Main Menu

        this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
    }
}

void GameOverState::Draw(float dt)
{
    this->_data->window.clear();

    for(auto &texts : gameOverTexts) {
        this->_data->window.draw(texts);
    }

    this->_view.setCenter(sf::Vector2f(SCREEN_WIDTH /3.0f, SCREEN_HEIGHT/2.0f));

    this->_data->window.setView(this->_view);

    this->_data->window.display();
}

void GameOverState::storeScore() {

    /*std::ifstream readFile;
    readFile.open(HIGHSCORE_FILE);

    if( readFile.is_open() )
    {
        while(!readFile.eof())
        {
            readFile >> this->_data->highScore;
        }
    }*/

    //readFile.close();

    std::ofstream writeFile(HIGHSCORE_FILE);

    if( writeFile.is_open() )
    {
        if(score > this->_data->highScore)
            this->_data->highScore = score;
    }

    writeFile << this->_data->highScore;

    writeFile.close();
}
