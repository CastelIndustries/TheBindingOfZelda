//
// Created by nicola on 16/03/19.
//

#include "ObserverReward.h"
#include "iostream"
#include "TileMap.h"
#include "CharacterFactory.h"

void ObserverReward::newLevel(TileMap &map, sf::RenderWindow &window) {

    map.LoadColMap();
    map.load("../Textures/tileset3.png", window, true);


}

void ObserverReward::update(TileMap &map, sf::RenderWindow &window) {

    for (int i = 0; i < map.width; i++) {
        for (int j = 0; j < map.height; j++) {
            if (map.map[j][i] == 3) {
                map.map[j][i] = 4;
            }
        }

    }

    map.load("../Textures/tileset3.png", window, true);



}

void ObserverReward::key(Element* &key, sf::RenderWindow &window) {
        key->Draw(window);

}
