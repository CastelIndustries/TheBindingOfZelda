//
// Created by frangio on 24/03/19.
//

#ifndef SFML_TESTS_LINK_HUD_H
#define SFML_TESTS_LINK_HUD_H

#include <SFML/Graphics.hpp>


class HUD {
public:

    HUD(){
        heartTexture.loadFromFile("../Textures/Heart.png");
        heart.setTexture(heartTexture);
        heart.setScale(0.5, 0.5);

        for(int i=0; i<3; i++) {
            hearts.push_back(heart);
        }


    }

    void renderHUD(sf::View &viewHUD, sf::RenderWindow &window){

        for(auto h:hearts){
            for(int i=0; i<hearts.size(); i++) {
                h.setPosition(viewHUD.getCenter().x + viewHUD.getSize().x * 1.7f - i*(heartTexture.getSize().x)*h.getScale().x, viewHUD.getCenter().y - viewHUD.getSize().y * 1.8f);
                window.draw(h);
            }
        }

    }




private:
    std::vector<sf::Sprite> hearts;
    sf::Sprite heart;
    sf::Texture heartTexture;

};


#endif //SFML_TESTS_LINK_HUD_H
