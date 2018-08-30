//
// Created by frangio on 30/08/18.
//

#ifndef SFML_TESTS_LINK_CHARACTER_H
#define SFML_TESTS_LINK_CHARACTER_H

#include "Animation.h"
#include <SFML/Graphics.hpp>

class Character {
public:
    Character();

    virtual ~Character();

    sf::RectangleShape playerBorder;
    virtual void Update(float deltaTime, sf::RenderWindow& window);
    virtual void Draw(sf::RenderWindow& window);
    virtual void CorrectDisplay(sf::RenderWindow& window);
    Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);



protected:
    float speed, dash;
    sf::RectangleShape body;
    Animation animation;
    unsigned  int row;
};


#endif //SFML_TESTS_LINK_CHARACTER_H
