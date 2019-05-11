//
// Created by frangio on 24/03/19.
//

#ifndef SFML_TESTS_LINK_HUD_H
#define SFML_TESTS_LINK_HUD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"


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
        kills.setFont(font);
        kills.setScale(4.0, 4.0);

        //TEST
        posXtest.setFont(font);
        posYtest.setFont(font);

    }

    void renderHUD(sf::View &viewHUD, sf::RenderWindow &window, Character *player);





private:
    std::vector<sf::Sprite> hearts;
    sf::Sprite heart;
    sf::Texture heartTexture;
    sf::Text kills;
    sf::Font font;



    //TEST
    sf::Text posXtest;

    sf::Text posYtest;




};


#endif //SFML_TESTS_LINK_HUD_H
