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

    void renderHUD(sf::View &viewHUD, sf::RenderWindow &window, Character* player){
        float posX = viewHUD.getCenter().x;
        float posY = viewHUD.getCenter().y;

        for(auto h:hearts){
            for(int i=0; i<hearts.size(); i++) {
                h.setPosition(posX + viewHUD.getSize().x * 1.7f - i*(heartTexture.getSize().x)*h.getScale().x, posY - viewHUD.getSize().y * 1.8f);
                window.draw(h);
            }
        }

        hudTexts[killText].setPosition(posX + viewHUD.getSize().x * 1.7f -580 , posY - viewHUD.getSize().y * 1.7f +300);
        hudTexts[killText].setString("Kills:"+ std::to_string(player->l_kills));
        hudTexts[1].setOrigin(hudTexts[1].getGlobalBounds().width /4 , hudTexts[1].getGlobalBounds().height / 4);
        //hudTexts[1].setPosition(window.getSize().x /2.0f , 50 );
        hudTexts[1].setPosition(posX, posY - viewHUD.getSize().y * 1.8f);
        hudTexts[1].setString("Enter the door for the next level");



        if(player->roomCompletedText)
            window.draw(hudTexts[1]);
        window.draw(hudTexts[killText]);
    }





private:
    std::vector<sf::Sprite> hearts;
    sf::Sprite heart;
    sf::Texture heartTexture;
    sf::Text hudTexts[NUM_HUD_TEXTS];
    sf::Font font;
    int killText=0;
};


#endif //SFML_TESTS_LINK_HUD_H
