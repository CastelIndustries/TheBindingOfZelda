//
// Created by frangio on 24/03/19.
//

#include "HUD.h"

void HUD::renderHUD(sf::View &viewHUD, sf::RenderWindow &window, Character *player) {
    float posX = viewHUD.getCenter().x + viewHUD.getSize().x * 1.7f;
    float posY = viewHUD.getCenter().y - viewHUD.getSize().y * 1.8f;

    for (auto h:hearts) {
        for (int i = 0; i < hearts.size(); i++) {
            h.setPosition(viewHUD.getCenter().x + viewHUD.getSize().x * 1.7f -
                          i * (heartTexture.getSize().x) * h.getScale().x,
                          viewHUD.getCenter().y - viewHUD.getSize().y * 1.8f);
            window.draw(h);
        }
    }

    kills.setPosition(posX - 580, posY + 300);
    kills.setString("Kills:" + std::to_string(player->totalKills));
    window.draw(kills);
}
