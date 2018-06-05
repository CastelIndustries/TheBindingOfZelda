//
// Created by frangio on 04/06/18.
//

#include "Maps.h"
#include "Maps.h"
#include <SFML/Graphics.hpp>
Maps::Maps() {
    int k=0,x=0,y=0;
    this->one.loadFromFile("../Textures/ground_1.jpeg");
    this->two.loadFromFile("../Textures/ground_2.jpeg");

    for (int i = 0; i <numTextures ; ++i) {
        for (int j = 0; j <numTextures ; ++j) {
            this->blocks[k].updateBlock(&this->one,&this->two);
            this->blocks[k].setPosition(x,y);

            x+=175;
            k++;

        }
        x=0;
        y+=175;
        k++;
    }
}
Maps::~Maps() {}
void Maps::showMaps(sf::RenderWindow &window) {
    int k=0;
    for (int i = 0; i <numTextures ; ++i) {
        for (int j = 0; j <numTextures ; ++j) {
            this->blocks[k].showBlock(window);


            k++;
        }
        k++;
    }
}