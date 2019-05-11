//
// Created by frangio on 23/08/18.
//

#include "Element.h"
#include <string>
#include <vector>
#include <random>

Element::Element(int dimX, int dimY, std::string filename, float scaleX, float scaleY) {

    std::uniform_int_distribution<int> distrX(2963, 8280);
    std::uniform_int_distribution<int> distrY(1757, 4336);
    std::random_device generator;
    std::mt19937 eng(generator());
    sf::RenderWindow window(sf::VideoMode(1211, 865), "Legend of Zelda", sf::Style::Close);
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(distrX(eng), distrY(eng));
    //sprite.setPosition(rand()%(window.getSize().x-dimX), rand()%(window.getSize().y-dimY));
    sprite.setScale(scaleX, scaleY);
    elementBorder.setSize(sf::Vector2f(dimX, dimY));
    elementBorder.setFillColor(sf::Color::Transparent);
    elementBorder.setPosition(sprite.getPosition());


}

void Element::Draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(elementBorder);

}
