//
// Created by nicola on 8/28/18.
//

#ifndef SFML_TESTS_LINK_CHARACTER_H
#define SFML_TESTS_LINK_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"


class Character {

public:

    sf::RectangleShape playerBorder;

    Character();

    virtual  ~Character();

    virtual void Update(float deltaTime, sf::RenderWindow &window);

    virtual void Draw(sf::RenderWindow &window);

    virtual void CorrectDisplay(sf::RenderWindow &window);

    virtual void Create(float deltatime, sf::RenderWindow &window);

    Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);

protected:
    float speed, dash;
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;

};


#endif //SFML_TESTS_LINK_CHARACTER_H
