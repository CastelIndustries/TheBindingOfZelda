//
// Created by frangio on 23/08/18.
//

#include "Element.h"
#include <string>
#include <vector>

Element::Element(int dimX, int dimY, std::string filename, float scaleX, float scaleY) {

    sf::RenderWindow window(sf::VideoMode(1211, 865), "Legend of Zelda", sf::Style::Close);
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(rand()%(window.getSize().x-dimX), rand()%(window.getSize().y-dimY));
    sprite.setScale(scaleX, scaleY);
    elementBorder.setSize(sf::Vector2f(dimX, dimY));
    elementBorder.setFillColor(sf::Color::Transparent);
    elementBorder.setPosition(sprite.getPosition());
}

void Element::Draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(elementBorder);

}
