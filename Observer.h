//
// Created by nicola on 16/03/19.
//

#ifndef SFML_TESTS_LINK_OBSERVER_H
#define SFML_TESTS_LINK_OBSERVER_H

#include <list>

class TileMap;
class Character;
class CharacterFactory;

class Observer{
protected:
    virtual ~Observer(){};
     Observer(){};

public:
    virtual void newLevel(TileMap &map, sf::RenderWindow &window)=0;
    virtual void update(TileMap &map, sf::RenderWindow &window) = 0;


};
#endif //SFML_TESTS_LINK_OBSERVER_H
