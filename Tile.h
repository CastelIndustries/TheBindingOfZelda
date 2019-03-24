//
// Created by frangio on 21/03/19.
//

#ifndef SFML_TESTS_LINK_TILE_H
#define SFML_TESTS_LINK_TILE_H


#include <SFML/Graphics.hpp>
#include "Collider.h"

class Tile {
public:
    explicit Tile(sf::Vector2f(position), bool w=true){
        tile.setSize(sf::Vector2f(175,175));
        tile.setFillColor(sf::Color::Transparent);
        tile.setPosition(position);
        walkable=w;
    };

    void drawSingleTile(sf::RenderWindow &window){
        window.draw(tile);
    };

    Collider GetCollider() {
        return Collider(tile);
    }

    bool getWalk(){
        return walkable;
    }

    sf::RectangleShape tile;
private:
    bool walkable;
};


#endif //SFML_TESTS_LINK_TILE_H
