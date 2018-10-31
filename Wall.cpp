//
// Created by frangio on 17/10/18.
//

#include "Wall.h"

Wall::Wall(sf::RenderWindow& window){

    leftWall.setSize(sf::Vector2f(100, window.getSize().y+200));
    leftWall.setPosition(-100, -100);
    rightWall.setSize(sf::Vector2f(100, window.getSize().y+200));
    rightWall.setPosition(window.getSize().x, -100);
    upWall.setSize((sf::Vector2f(window.getSize().x+200, 100)));
    upWall.setPosition(-100, -100);
    downWall.setSize((sf::Vector2f(window.getSize().x+200, 100)));
    downWall.setPosition(-100, window.getSize().y);

}

void Wall::Draw(sf::RenderWindow &window) {
    window.draw(leftWall);
    window.draw(rightWall);
    window.draw(upWall);
    window.draw(downWall);


}
