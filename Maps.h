//
// Created by frangio on 04/06/18.
//

#ifndef SFML_TESTS_LINK_MAPS_H
#define SFML_TESTS_LINK_MAPS_H


#include <SFML/Graphics/Texture.hpp>
#include "Block.h"

class Maps {
public:
    Maps(int origin);
    ~Maps();

    void showMaps(sf::RenderWindow &window);

protected:
    sf::Texture one;
    sf::Texture two;
    sf::Texture three;
    //sf::Texture four;
    Block blocks[200];
    static const int numTiles=10;


};


#endif //SFML_TESTS_LINK_MAPS_H