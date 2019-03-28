//
// Created by nicola on 16/03/19.
//

#ifndef SFML_TESTS_LINK_OBSERVERREWARD_H
#define SFML_TESTS_LINK_OBSERVERREWARD_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Observer.h"


class ObserverReward: public Observer {
public:

    ObserverReward(){};

void update() override;
void update(TileMap &map, sf::RenderWindow &window) override;



};


#endif //SFML_TESTS_LINK_OBSERVERREWARD_H
