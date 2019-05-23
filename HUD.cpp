//
// Created by frangio on 24/03/19.
//

#include "HUD.h"
void HUD::renderHUD(sf::View &viewHUD, sf::RenderWindow &window, Character* player){
    float posX = viewHUD.getCenter().x;
    float posY = viewHUD.getCenter().y;

    for(auto h:hearts){
        for(int i=0; i<hearts.size(); i++) {
            h.setPosition(posX + viewHUD.getSize().x * 1.7f - i*(heartTexture.getSize().x)*h.getScale().x, posY - viewHUD.getSize().y * 1.8f);
            window.draw(h);
        }
    }

    hudTexts[killText].setPosition(posX + viewHUD.getSize().x * 1.7f - 610 , posY - viewHUD.getSize().y * 1.7f +300);
    hudTexts[killText].setString("Kills:"+ std::to_string(player->l_kills));
    hudTexts[1].setOrigin(hudTexts[1].getGlobalBounds().width /4 , hudTexts[1].getGlobalBounds().height / 4);
    hudTexts[1].setPosition(posX, posY - viewHUD.getSize().y * 1.8f);
    hudTexts[1].setString("Enter the door for the next level");



    if(player->roomCompletedText)
        window.draw(hudTexts[1]);
    window.draw(hudTexts[killText]);
}