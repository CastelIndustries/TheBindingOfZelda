//
// Created by nicola on 16/03/19.
//

#include "ObserverReward.h"
#include "iostream"
#include "TileMap.h"

void ObserverReward::update() {
    std::cout<<"Room completed"<<std::endl;


}

void ObserverReward::update(TileMap &map, sf::RenderWindow &window){


    //map.LoadColMap("../Textures/Map.txt");
    map.map[12][30] = 1;
    map.map[13][30] = 1;
    map.map[16][22] = 1;
    map.map[16][23] = 1;


    map.load("../Textures/tileset3.png", 71, 36, window, true);


}