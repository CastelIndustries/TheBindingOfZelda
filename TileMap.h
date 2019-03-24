//
// Created by frangio on 31/10/18.
//

#ifndef SFML_TESTS_LINK_TILEMAP_H
#define SFML_TESTS_LINK_TILEMAP_H


#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Collider.h"
#include "Character.h"
#include <list>


class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    bool load(const std::string& tilesetFile, sf::Vector2u tileSize, unsigned int width, unsigned int height, sf::RenderWindow &window);


    void checkCollision(std::list<std::unique_ptr<Character>> &characterList);

    void drawColTile(sf::RenderWindow &window){
        for(auto tiles:colTiles) {
            tiles->drawSingleTile(window);
        }
    }

    sf::RectangleShape getTile() const{
        for(auto tiles:colTiles)
            tiles->tile;
    }

    void LoadColMap(const char*filename);

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states)  const ;

    sf::VertexArray vertices;
    sf::Texture tileset;
    std::vector<Tile*> colTiles;
    std::vector<std::vector<int>> colMap;

};



#endif //SFML_TESTS_LINK_TILEMAP_H
