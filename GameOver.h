//
// Created by frangio on 13/05/19.
//

#ifndef SFML_TESTS_LINK_GAMEOVER_H
#define SFML_TESTS_LINK_GAMEOVER_H


#include <SFML/Graphics.hpp>
#include <time.h>

class GameOver {
public:
    GameOver(float width, float height){
        font.loadFromFile("../Textures/font.ttf");
        end[0].setFont(font);
        end[0].setString("YOU DIED");
        end[0].setOrigin(end[0].getGlobalBounds().width/2, end[0].getGlobalBounds().height/2);
        end[0].setPosition(sf::Vector2f(width /2.0f, height / 2.0f));

    };

    bool gameover(sf::RenderWindow &window){

        window.clear();
        window.draw(end[0]);
        if(endClock.getElapsedTime() > timeLast)
            return true;
        else
            return false;
    }
    sf::Clock endClock;
private:

    const sf::Time timeLast = sf::seconds(5.0f);
    sf::Text end[1];
    sf::Font font;
};


#endif //SFML_TESTS_LINK_GAMEOVER_H
