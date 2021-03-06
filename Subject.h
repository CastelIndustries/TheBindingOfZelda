//
// Created by nicola on 16/03/19.
//

#ifndef SFML_TESTS_LINK_SUBJECT_H
#define SFML_TESTS_LINK_SUBJECT_H

#include "Observer.h"
#include <list>
class Subject{
protected:
    virtual ~Subject() {};

public:
    virtual  void RegisterObserver(Observer* observer){}
    virtual void RemoveObserver(Observer* observer){}
    virtual void NotifyObservers(GameDataRef &_data, TileMap &map, sf::RenderWindow &window, HUD &hud){}
    std::list<Observer*> observers;

};
#endif //SFML_TESTS_LINK_SUBJECT_H
