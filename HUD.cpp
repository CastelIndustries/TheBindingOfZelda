//
// Created by frangio on 24/03/19.
//

#include "HUD.h"
void HUD::renderHUD(sf::View &viewHUD, sf::RenderWindow &window, Character* player, int heartTotal){
    float posX = viewHUD.getCenter().x;
    float posY = viewHUD.getCenter().y;

    for(auto h:hearts){
        for(int i=0; i< heartTotal; i++) {
            h.setPosition(posX + viewHUD.getSize().x * 1.7f - i*(heartTexture.getSize().x)*h.getScale().x, posY - viewHUD.getSize().y * 1.8f);
            window.draw(h);
        }
    }

    hudTexts[killText].setPosition(posX + viewHUD.getSize().x * 1.7f - 610 , posY - viewHUD.getSize().y * 1.7f +300);
    hudTexts[killText].setString("Kills:"+ std::to_string(player->l_kills));
    hudTexts[enterDoor].setOrigin(hudTexts[enterDoor].getGlobalBounds().width /4 , hudTexts[enterDoor].getGlobalBounds().height / 4);
    hudTexts[enterDoor].setPosition(posX, posY - viewHUD.getSize().y * 1.8f);
    hudTexts[enterDoor].setString("Enter the door for the next level");



    if(player->roomCompletedText)
        window.draw(hudTexts[enterDoor]);
    window.draw(hudTexts[killText]);
}

bool HUD::lifePointRemove(Character *player) {
    if(player->hp == 66 && hearts.size() == 3 ) {
        hearts.back();
        hearts.pop_back();
    }
    if(player->hp <= 32 && hearts.size() == 2 )
        hearts.pop_back();
    if(player->hp <= 0 && hearts.size() == 1 ) {
        hearts.pop_back();
        return true;
    }else
        return false;
}

