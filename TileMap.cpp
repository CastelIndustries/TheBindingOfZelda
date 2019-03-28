//
// Created by frangio on 31/10/18.
//

#include <fstream>
#include <sstream>
#include <random>
#include "TileMap.h"

bool TileMap::load(const std::string &tilesetFile, unsigned int width, unsigned int height, sf::RenderWindow &window, bool newLevel) {
    // load the tilesetFile texture
    if (!tileset.loadFromFile(tilesetFile))
        return false;
    if(newLevel)
        colTiles.clear();

    // resize the vertex array to fit the level size
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {
            // get the current tile number
            int tileNumber = map[j][i];


            switch(tileNumber) {

                case 0 :
                    colTiles.push_back(new Tile(sf::Vector2f(i * tileSize.x, j * tileSize.y), false));
                    break;
                case 1:
                    colTiles.push_back(new Tile(sf::Vector2f(i * tileSize.x, j * tileSize.y)));
                    break;
                case 3 :
                    colTiles.push_back(new Tile(sf::Vector2f(i * tileSize.x, j * tileSize.y), false, false));
                    break;
                default:
                    break;
            }
            // find its position in the tilesetFile texture
            int tu = tileNumber % (tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex *quad = &vertices[(i + j * width) * 4];



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
    }
    return true;
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &tileset;

    // draw the vertex array
    target.draw(vertices, states);

}

void TileMap::checkCollision(std::list<std::unique_ptr<Character>> &characterList, Character* player) {

    std::random_device generator;
    std::mt19937 eng(generator());
    std::uniform_int_distribution<int> distrX(2963, 8280);
    std::uniform_int_distribution<int> distrY(1757, 4336);


    for (auto &character : characterList) {
        for (auto &tiles_to_draw : colTiles) {       //Collision characters-tiles

            if (!tiles_to_draw->getWalk()) {
                character->GetCollider().CheckCollision(tiles_to_draw->GetCollider(), 0.0f);
            }
                if (!tiles_to_draw->getInMap() && character.get() != player &&
                    character->GetCollider().CheckCollision(tiles_to_draw->GetCollider(), 0.0f))
                    character->body.setPosition(distrX(eng), distrY(eng));


        }
    }
}

void TileMap::LoadColMap(const char*filename){

    std::ifstream openFile(filename);
    std::vector<int> tempMap;
    this->map.clear();

    if(openFile.is_open()){
        while(!openFile.eof()){
            std::string str, value;
            std::getline(openFile, str);
            std::stringstream stream(str);

            while(std::getline(stream, value, ' ')){
                if(value.length()>0){
                    int a = 2;
                    if(value == "0" || value == "1" || value == "2") {
                        a = atoi(value.c_str());
                    }
                    tempMap.push_back(a);
                }

            }
            this->map.push_back(tempMap);
            tempMap.clear();
        }
    }

}

