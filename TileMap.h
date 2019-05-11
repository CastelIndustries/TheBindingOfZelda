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
#include <random>


class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    TileMap(unsigned int w, unsigned int h, sf::Vector2u tS){

        width = w;
        height = h;
        tileSize = tS;
    }

    bool load(const std::string& tilesetFile, sf::RenderWindow &window, bool newLevel = false);

    void checkCollision(std::list<std::unique_ptr<Character>> &characterList, Character* player);

    void drawColTile(sf::RenderWindow &window){
        for(auto tiles:colTiles) {
            tiles->drawSingleTile(window);
        }
    }

    void LoadColMap(const char*filename);

    ~TileMap(){}

    std::vector<std::vector<int>> map;

    unsigned  int width;
    unsigned  int height;
    std::vector<Tile*> colTiles;

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states)  const ;

    sf::VertexArray vertices;
    sf::Texture tileset;

    sf::Vector2u tileSize = sf::Vector2u(175, 175);





};



#endif //SFML_TESTS_LINK_TILEMAP_H
