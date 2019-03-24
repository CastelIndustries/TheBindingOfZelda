//
// Created by nicola on 16/03/19.
//

#ifndef SFML_TESTS_LINK_OBSERVERREWARD_H
#define SFML_TESTS_LINK_OBSERVERREWARD_H

#include "Observer.h"

class ObserverReward: public Observer {
public:

    ObserverReward(){};

void update() override;


};


#endif //SFML_TESTS_LINK_OBSERVERREWARD_H
