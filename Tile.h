//
// Created by frangio on 21/03/19.
//

#ifndef SFML_TESTS_LINK_TILE_H
#define SFML_TESTS_LINK_TILE_H


#include <SFML/Graphics.hpp>
#include "Collider.h"

class Tile {
public:
    explicit Tile(sf::Vector2f(position), bool w=true, bool in=true, bool o=false){
        tile.setSize(tileSize);
        tile.setFillColor(sf::Color::Transparent);
        tile.setPosition(position);
        walkable=w;
        inMap=in;
        open=o;


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
    bool getInMap(){
        return inMap;
    }

    bool getOpen(){
        return open;
    }

    sf::RectangleShape tile;
    sf::Vector2f tileSize = sf::Vector2f(175.0f, 175.0f);

private:
    bool walkable;
    bool inMap;
    bool open;




};


#endif //SFML_TESTS_LINK_TILE_H
