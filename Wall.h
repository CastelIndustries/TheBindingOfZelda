//
// Created by frangio on 17/10/18.
//

#ifndef SFML_TESTS_LINK_WALL_H
#define SFML_TESTS_LINK_WALL_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "Collider.h"

class Wall {
public:
    sf::RectangleShape leftWall;
    sf::RectangleShape rightWall;
    sf::RectangleShape upWall;
    sf::RectangleShape downWall;

    Wall(sf::RenderWindow& window);
    ~Wall(){};

    Collider GetColliderLeft() {
        return Collider(leftWall);
    }

    Collider GetColliderRight() {
        return Collider(rightWall);
    }

    Collider GetColliderUp() {
        return Collider(upWall);
    }

    Collider GetColliderDown() {
        return Collider(downWall);
    }

    void Draw(sf::RenderWindow& window);

};


#endif //SFML_TESTS_LINK_WALL_H
