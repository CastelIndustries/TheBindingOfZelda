//
// Created by frangio on 23/08/18.
//

#ifndef SFML_TESTS_LINK_ELEMENT_H
#define SFML_TESTS_LINK_ELEMENT_H


#include <SFML/Graphics.hpp>

class Element {
public:
    Element(int dimX, int dimY, std::string string,float scaleX=1, float scaleY=1);
    void Draw(sf::RenderWindow &window);
    sf::RectangleShape elementBorder;
private:
    sf::Sprite sprite;
    sf::Texture texture;

};


#endif //SFML_TESTS_LINK_ELEMENT_H
