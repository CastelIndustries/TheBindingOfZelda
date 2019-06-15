//
// Created by nicola on 10/06/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_MELEESTRATEGY_H
#define THEBINDINGOFZELDAPROJECT_MELEESTRATEGY_H

#include "Strategy.h"
#include "Character.h"

class MeleeStrategy : public Strategy {
public:


    void Attack(Character *player, Character &character, float deltaTime, sf::RenderWindow &window) override;

};


#endif //THEBINDINGOFZELDAPROJECT_MELEESTRATEGY_H
