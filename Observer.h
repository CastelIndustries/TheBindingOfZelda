//
// Created by nicola on 16/03/19.
//

#ifndef SFML_TESTS_LINK_OBSERVER_H
#define SFML_TESTS_LINK_OBSERVER_H

class TileMap;

class Observer{
protected:
    virtual ~Observer(){};
     Observer(){};

public:
    virtual void update()=0;
    virtual void update(TileMap &map, sf::RenderWindow &window) = 0;


};
#endif //SFML_TESTS_LINK_OBSERVER_H
