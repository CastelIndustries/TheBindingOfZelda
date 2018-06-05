//
// Created by frangio on 24/04/18.
//

#ifndef SFML_TESTS_PLAYER_H
#define SFML_TESTS_PLAYER_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "Animation.h"


class Player
{
public:
    Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~Player();

    void Update(float deltaTime, sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);
    void CorrectDisplay(sf::RenderWindow& window);


public:
    sf::RectangleShape playerBorder;


private:
    float speed, dash;
    sf::RectangleShape body;
    Animation animation;
    unsigned  int row;
};


#endif //SFML_TESTS_PLAYER_H
