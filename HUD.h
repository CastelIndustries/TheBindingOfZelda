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

    void renderHUD(sf::View &viewHUD, sf::RenderWindow &window, Character* player){
        float posX = viewHUD.getCenter().x + viewHUD.getSize().x * 1.7f;
        float posY = viewHUD.getCenter().y - viewHUD.getSize().y * 1.8f;

        for(auto h:hearts){
            for(int i=0; i<hearts.size(); i++) {
                h.setPosition(viewHUD.getCenter().x + viewHUD.getSize().x * 1.7f - i*(heartTexture.getSize().x)*h.getScale().x, viewHUD.getCenter().y - viewHUD.getSize().y * 1.8f);
                window.draw(h);
            }
        }

        kills.setPosition(posX-580 , posY+300);
        kills.setString("Kills:"+ std::to_string(player->kills));
        posXtest.setString("posX: " + std::to_string(player->body.getPosition().x));
        posXtest.setPosition(posX-580 , posY+500);
        posYtest.setString("posy: " + std::to_string(player->body.getPosition().y));
        posYtest.setPosition(posX-580 , posY+700);



        window.draw(kills);
        window.draw(posXtest);
        window.draw(posYtest);

        /*for(int i=0; i<nCoin; i++){
            if(player.playerBorder.getGlobalBounds().intersects(coins[i]->coinBorder.getGlobalBounds())){
                coins.erase(coins.begin() + i);
                nCoin--;
                count++;
                coinSound.play();
            }
        }
        pickedCoins.setString("COINS : "+ std::to_string(count));
        window.draw(pickedCoins);*/


    }




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
