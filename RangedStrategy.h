//
// Created by nicola on 10/06/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_RANGEDSTRATEGY_H
#define THEBINDINGOFZELDAPROJECT_RANGEDSTRATEGY_H

#include "Strategy.h"
#include "DEFINITIONS.h"
#include "Character.h"


class RangedStrategy : public Strategy {

public:

    void Attack(Character *player, Character &character, float deltaTime, sf::RenderWindow &window) override;

    RangedStrategy();
};


#endif //THEBINDINGOFZELDAPROJECT_RANGEDSTRATEGY_H
