//
// Created by frangio on 04/06/18.
//

#ifndef SFML_TESTS_LINK_BLOCK_H
#define SFML_TESTS_LINK_BLOCK_H

#include <SFML/Graphics.hpp>
#include <ctime>
class Block {
public:
    Block();
    ~Block();

    void showBlock( sf::RenderWindow &window);

    void updateBlock(sf::Texture *one, sf::Texture *two, sf::Texture *three, sf::Texture *four);
    void setPosition(int x, int y);

protected:
    int type;
    sf::Sprite terrain;
};



#endif //SFML_TESTS_LINK_BLOCK_H
