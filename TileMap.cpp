//
// Created by frangio on 31/10/18.
//

#include "TileMap.h"

bool TileMap::load(const std::string &tilesetFile, const int *tiles, unsigned int width, unsigned int height)
{
    // load the tilesetFile texture
    if (!tileset.loadFromFile(tilesetFile))
        return false;

    // resize the vertex array to fit the level size
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i + j * width];
            if(tileNumber==0){
                tileNumber=rand() % 3;
            }

            if(tileNumber==3)
                walkable=false;
            else
                walkable=true;

            // find its position in the tilesetFile texture
            int tu = tileNumber % (tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}


void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &tileset;

    // draw the vertex array
    target.draw(vertices, states);

}



