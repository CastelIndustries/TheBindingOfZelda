//
// Created by frangio on 25/04/18.
//

#ifndef SFML_TESTS_LINK_COIN_H
#define SFML_TESTS_LINK_COIN_H


#include <SFML/Graphics.hpp>
#include "Animation.h"

class Coin {
public:
    Coin(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, int value, float posX, float posY);
    ~Coin();

    void rotate(float deltaTime);
    void Draw(sf::RenderWindow& window);

public:
    sf::RectangleShape coinBorder;
private:
    sf::RectangleShape body;
    Animation animation;

};


#endif //SFML_TESTS_LINK_COIN_H
