//
// Created by frangio on 04/06/18.
//

#include "Maps.h"
#include "Maps.h"
#include <SFML/Graphics.hpp>
Maps::Maps() {
    int k=0,x=0,y=0;
    this->one.loadFromFile("../Textures/tiles 1b.png");
    this->two.loadFromFile("../Textures/tiles 2b.png");
    this->three.loadFromFile("../Textures/tiles 3b.png");


    for (int i = 0; i <numTextures ; ++i) {
        for (int j = 0; j <numTextures+4 ; ++j) {
            this->blocks[k].updateBlock(&this->one, &this->two, &this->three);//, &this->four);
            this->blocks[k].setPosition(x,y);

            x += 86;
            k++;

        }
        x=0;
        y += 86;
        k++;
    }
}
Maps::~Maps() {}
void Maps::showMaps(sf::RenderWindow &window) {
    int k=0;
    for (int i = 0; i <numTextures ; ++i) {
        for (int j = 0; j <numTextures+4 ; ++j) {
            this->blocks[k].showBlock(window);

            k++;
        }
        k++;
    }
}