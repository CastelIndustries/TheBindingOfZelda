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
    bool load(const std::string& tilesetFile, unsigned int width, unsigned int height, sf::RenderWindow &window, bool newLevel = false);


    void checkCollision(std::list<std::unique_ptr<Character>> &characterList, Character* player);

    void drawColTile(sf::RenderWindow &window){
        for(auto tiles:colTiles) {
            tiles->drawSingleTile(window);
        }
    }

    Tile getTile() const {
        for(auto tiles:colTiles)
            tiles->tile;
    }

    void LoadColMap(const char*filename);

    std::vector<std::vector<int>> map;

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states)  const ;

    sf::VertexArray vertices;
    sf::Texture tileset;
    std::vector<Tile*> colTiles;
    sf::Vector2u tileSize = sf::Vector2u(175, 175);


};



#endif //SFML_TESTS_LINK_TILEMAP_H
