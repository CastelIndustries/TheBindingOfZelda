//
// Created by frangio on 23/05/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_INPUTMANAGER_H
#define THEBINDINGOFZELDAPROJECT_INPUTMANAGER_H

#include<SFML/Graphics.hpp>

class InputManager
{
public:
    InputManager() {}
    ~InputManager() {}

    bool IsTextSelectioned(sf::Text text, sf::RenderWindow &window);

};


#endif //THEBINDINGOFZELDAPROJECT_INPUTMANAGER_H
