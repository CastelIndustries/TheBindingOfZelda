//
// Created by frangio on 06/06/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_STRATEGY_H
#define THEBINDINGOFZELDAPROJECT_STRATEGY_H

#include <SFML/Graphics.hpp>

class Character;

class Strategy{
public:
    virtual void Attack(Character& character, float  deltaTime, sf::RenderWindow &window)=0;

};

#endif //THEBINDINGOFZELDAPROJECT_STRATEGY_H
