//
// Created by frangio on 9/29/18.
//

#ifndef SFML_TESTS_LINK_COLLIDER_H
#define SFML_TESTS_LINK_COLLIDER_H
#


#include <SFML/Graphics.hpp>

class Collider {
public:
    Collider(sf::RectangleShape &body);

    ~Collider() {};

    void Move(float dx, float dy) {
        body.move(dx, dy);

    }

    bool CheckCollision(Collider other, float push);

    sf::Vector2f GetPosition() { return body.getPosition(); };

    sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; };


private:
    sf::RectangleShape &body;
};


#endif //SFML_TESTS_LINK_COLLIDER_H
