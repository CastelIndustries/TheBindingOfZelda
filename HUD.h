//
// Created by frangio on 24/03/19.
//

#ifndef SFML_TESTS_LINK_HUD_H
#define SFML_TESTS_LINK_HUD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "DEFINITIONS.h"
#include "Subject.h"




class HUD {
public:



    HUD();

    void renderHUD(sf::View &viewHUD, sf::RenderWindow &window, Character* player, int heartTotal);

    bool lifePointRemove(Character* player);

    sf::Text hudTexts[3];
    sf::Clock bestClock;

private:
    std::vector<sf::Sprite> hearts;
    sf::Sprite heart;
    sf::Texture heartTexture;

    sf::Font font;
};


#endif //SFML_TESTS_LINK_HUD_H
