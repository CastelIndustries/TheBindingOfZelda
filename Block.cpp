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

void Block::updateBlock(sf::Texture *one, sf::Texture *two, sf::Texture *three){//, sf::Texture *four) {
    switch (type) {
        case 0:
            this->terrain.setTexture(*one);
            this->terrain.setScale(0.5, 0.5);
            break;
        case 1:
            this->terrain.setTexture(*two);
            this->terrain.setScale(0.5, 0.5);
            break;
        case 2:
            this->terrain.setTexture(*three);
            this->terrain.setScale(0.5, 0.5);
            break;
            /*case 3:
                this->terrain.setTexture(*four);
                break;*/
    }
}
void Block::setPosition(int x, int y) {
    this->terrain.setPosition(x,y);
}