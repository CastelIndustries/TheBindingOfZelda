//
// Created by frangio on 24/03/19.
//

#ifndef SFML_TESTS_LINK_HUD_H
#define SFML_TESTS_LINK_HUD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

#define NUM_HUD_TEXTS 2


class HUD {
public:



    HUD(){
        heartTexture.loadFromFile("../Textures/Heart.png");
        heart.setTexture(heartTexture);
        heart.setScale(0.5, 0.5);

        for(int i=0; i<3; i++) {
            hearts.push_back(heart);
        }

        if(!font.loadFromFile("../Textures/font.ttf")){
            std::cout<<"Error! Could not load the file font.ttf" << std::endl;
        }
        hudTexts[killText].setFont(font);
        hudTexts[killText].setScale(4.0, 4.0);
        hudTexts[1].setFont(font);
        hudTexts[1].setScale(2.0, 2.0);
    }

    void renderHUD(sf::View &viewHUD, sf::RenderWindow &window, Character* player);

private:
    std::vector<sf::Sprite> hearts;
    sf::Sprite heart;
    sf::Texture heartTexture;
    sf::Text hudTexts[NUM_HUD_TEXTS];
    sf::Font font;
    int killText=0;
};


#endif //SFML_TESTS_LINK_HUD_H
