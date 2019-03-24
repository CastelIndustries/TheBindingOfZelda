//
// Created by frangio on 31/10/18.
//

#ifndef SFML_TESTS_LINK_TILEMAP_H
#define SFML_TESTS_LINK_TILEMAP_H


#include <SFML/Graphics.hpp>
#include "Collider.h"


class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const std::string& tilesetFile, const int* tiles, unsigned int width, unsigned int height);
    Collider getCollider(){
        return Collider(tile);
    }
    void drawTile(sf::RenderWindow &window, sf::RectangleShape &tile_m){
        window.draw(tile_m);
    }
private:
    sf::RectangleShape createRect(float x, float y){
        sf::RectangleShape tile;
        tile.setSize(sf::Vector2f(tileSize));
        tile.setPosition(x,y);
        tile.setFillColor(sf::Color::Green);
        return tile;
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::RectangleShape tile;
    sf::Vector2u tileSize = sf::Vector2u(175, 175);
    sf::VertexArray vertices;
    sf::Texture tileset;
    bool walkable;
};

#endif //SFML_TESTS_LINK_TILEMAP_H
