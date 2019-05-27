//
// Created by nicola on 16/03/19.
//

#ifndef SFML_TESTS_LINK_OBSERVER_H
#define SFML_TESTS_LINK_OBSERVER_H

#include <list>
#include "Game.h"

class TileMap;
class State;


class Observer{
protected:
    virtual ~Observer(){};
     Observer(){};

public:
    virtual void newLevel(GameDataRef &_data)=0;
    virtual void update(TileMap &map, sf::RenderWindow &window) = 0;


};
#endif //SFML_TESTS_LINK_OBSERVER_H
