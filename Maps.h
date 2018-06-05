//
// Created by frangio on 04/06/18.
//

#ifndef SFML_TESTS_LINK_MAPS_H
#define SFML_TESTS_LINK_MAPS_H


#include <SFML/Graphics/Texture.hpp>
#include "Block.h"

class Maps {
public:
    Maps();
    ~Maps();
    void showMaps(sf::RenderWindow &window);

protected:
    sf::Texture one;
    sf::Texture two;
    Block blocks[100];
    static const int numTextures=4;


};


#endif //SFML_TESTS_LINK_MAPS_H
