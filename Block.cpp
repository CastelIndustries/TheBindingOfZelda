//
// Created by frangio on 04/06/18.
//

#include "Block.h"
Block::Block() {
    this->type = rand() % 3;
}
Block::~Block() {}
void Block::showBlock(sf::RenderWindow &window) {
    window.draw(this->terrain);
}
void Block::updateBlock(sf::Texture *one, sf::Texture *two) {
    if(this->type>1)
        this->terrain.setTexture(*one);
    else
        this->terrain.setTexture(*two);
}
void Block::setPosition(int x, int y) {
    this->terrain.setPosition(x,y);
}