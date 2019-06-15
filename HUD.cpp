//
// Created by frangio on 24/03/19.
//

#include "HUD.h"

HUD::HUD(){
    heartTexture.loadFromFile(HEART_TEXTURE);
    heart.setTexture(heartTexture);
    heart.setScale(0.5, 0.5);

    if(!font.loadFromFile(FONT)){
        std::cout<<"Error! Could not load the file font.ttf" << std::endl;
    }



    for(int i=0; i<3; i++) {
        hearts.push_back(heart);
    }

    hudTexts[KILL_TEXT].setFont(font);
    hudTexts[ENTER_DOOR_TEXT].setFont(font);
    hudTexts[BEST_SCORE_TEXT].setFont(font);
    hudTexts[KILL_TEXT].setScale(4.0, 4.0);
    hudTexts[ENTER_DOOR_TEXT].setScale(2.0, 2.0);
    hudTexts[BEST_SCORE_TEXT].setScale(2.0, 2.0);
}

void HUD::renderHUD(sf::View &viewHUD, sf::RenderWindow &window, Character* player, int heartTotal){
    float posX = viewHUD.getCenter().x;
    float posY = viewHUD.getCenter().y;

    for(auto h:hearts){
        for(int i=0; i< heartTotal; i++) {
            h.setPosition(posX + viewHUD.getSize().x * 1.7f - i*(heartTexture.getSize().x)*h.getScale().x, posY - viewHUD.getSize().y * 1.8f);
            window.draw(h);
        }
    }

    hudTexts[KILL_TEXT].setPosition(posX + viewHUD.getSize().x * 1.7f - 610 , posY - viewHUD.getSize().y * 1.7f +300);
    hudTexts[KILL_TEXT].setString("Kills:"+ std::to_string(player->l_kills));
    hudTexts[ENTER_DOOR_TEXT].setOrigin(hudTexts[ENTER_DOOR_TEXT].getGlobalBounds().width /4 , hudTexts[ENTER_DOOR_TEXT].getGlobalBounds().height / 4);
    hudTexts[ENTER_DOOR_TEXT].setPosition(posX, posY - viewHUD.getSize().y * 1.8f);
    hudTexts[ENTER_DOOR_TEXT].setString("Enter the door for the next level");
    hudTexts[BEST_SCORE_TEXT].setOrigin(hudTexts[BEST_SCORE_TEXT].getGlobalBounds().width /4 , hudTexts[BEST_SCORE_TEXT].getGlobalBounds().height / 4);
    hudTexts[BEST_SCORE_TEXT].setPosition(posX, posY - viewHUD.getSize().y * 1.5f);
    hudTexts[BEST_SCORE_TEXT].setString("NEW HIGHSCORE!");
    hudTexts[BEST_SCORE_TEXT].setFillColor(sf::Color::Yellow);


    if(player->best) {
        window.draw(hudTexts[BEST_SCORE_TEXT]);
    }
    if(player->roomCompletedText)
        window.draw(hudTexts[ENTER_DOOR_TEXT]);

    window.draw(hudTexts[KILL_TEXT]);

}

bool HUD::lifePointRemove(Character *player) {
    if (player->hp == 2 && hearts.size() == 3) {
        hearts.back();
        hearts.pop_back();
    }
    if (player->hp == 1 && hearts.size() == 2) {
        hearts.pop_back();
    }
    if (player->hp == 0 && hearts.size() == 1) {
        hearts.pop_back();
        return true;
    }
    return false;
}



