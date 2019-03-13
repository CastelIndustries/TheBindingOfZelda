//
// Created by nicola on 06/03/19.
//

#ifndef SFML_TESTS_LINK_BULLET_H
#define SFML_TESTS_LINK_BULLET_H

#include <SFML/Graphics.hpp>


class Bullet{

public:
    Bullet(sf::Vector2f size, int dir);

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

    void Draw(sf::RenderWindow &window);

    bool CheckCollision(sf::RectangleShape& character);

private:
    sf::RectangleShape bullet;
    int BulletDir;
public:
    const sf::RectangleShape &getBullet() const;

    void setBullet(const sf::RectangleShape &bullet);

};


#endif //SFML_TESTS_LINK_BULLET_H
