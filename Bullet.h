//
// Created by nicola on 06/03/19.
//

#ifndef SFML_TESTS_LINK_BULLET_H
#define SFML_TESTS_LINK_BULLET_H

#include <SFML/Graphics.hpp>
#include "Collider.h"


class Bullet{

public:
    Bullet(std::string filename, sf::Vector2f size, int dir);

    float getRight() {
        return bullet.getPosition().x + bullet.getSize().x;
    }

    float getLeft () {
        return bullet.getPosition().x;
    }

    float  getTop() {
        return bullet.getPosition().y;
    }

    float getBottom() {
        return bullet.getPosition().y + bullet.getSize().y;
    }
    void fire(float speed);

    void setPos(sf::Vector2f NewPos);
    void setSize(sf::Vector2f newSize){
        bullet.setSize(newSize);
    }

    void Draw(sf::RenderWindow &window);

    bool CheckCollision(sf::RectangleShape& character);

    Collider GetCollider() {
        return Collider(bullet);
    }

    const sf::RectangleShape &getBullet() const;
    int damage;
    void setBullet(const sf::RectangleShape &bullet);


private:
    sf::Texture bulletTexture;
    sf::RectangleShape bullet;
    int BulletDir;



};


#endif //SFML_TESTS_LINK_BULLET_H
