//
// Created by frangio on 24/04/18.
//

#ifndef SFML_TESTS_PLAYER_H
#define SFML_TESTS_PLAYER_H

#include "Character.h"


class Player : public Character
{
public:
    Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed): Character(texture, imageCount, switchTime, speed){};
    virtual ~Player();

    virtual void Update(float deltaTime, sf::RenderWindow& window) override;
    virtual void Draw(sf::RenderWindow& window) override ;
    virtual void CorrectDisplay(sf::RenderWindow& window) override ;



private:
    float speed, dash;
    sf::RectangleShape body;
    Animation animation;
    unsigned  int row;
};


#endif //SFML_TESTS_PLAYER_H
