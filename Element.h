//
// Created by frangio on 23/08/18.
//

#ifndef SFML_TESTS_LINK_ELEMENT_H
#define SFML_TESTS_LINK_ELEMENT_H


#include <SFML/Graphics.hpp>
#include "Collider.h"
#include <random>

class Element {
public:
    Element(int dimX, int dimY, std::string filename,float scaleX=1, float scaleY=1);
    void Draw(sf::RenderWindow &window);
    void SetPosition(){
        std::uniform_int_distribution<int> distrX(2963, 8280);
        std::uniform_int_distribution<int> distrY(1757, 4336);
        std::random_device generator;
        std::mt19937 eng(generator());

        sprite.setPosition(distrX(eng), distrY(eng));
    }
    Collider GetCollider(){
        return Collider(elementBorder);
    }
    sf::RectangleShape elementBorder;
    sf::Sprite sprite;
private:

    sf::Texture texture;

};


#endif //SFML_TESTS_LINK_ELEMENT_H
