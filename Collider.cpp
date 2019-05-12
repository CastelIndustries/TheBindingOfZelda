//
// Created by frangio on 9/29/18.
//

#include <iostream>
#include "Collider.h"


Collider::Collider(sf::RectangleShape &body) : body(body) {
};

bool Collider::CheckCollision(Collider other, float push) {

    sf::Vector2f OtherPosition = other.GetPosition();
    sf::Vector2f OtherHalfSize = other.GetHalfSize();
    sf::Vector2f ThisPosition = GetPosition();
    sf::Vector2f ThisHalfSize = GetHalfSize();

    float deltaX = OtherPosition.x - ThisPosition.x;
    float deltaY = OtherPosition.y - ThisPosition.y;

    float IntersectX = abs(deltaX) - (ThisHalfSize.x + OtherHalfSize.x);
    float IntersectY = abs(deltaY) - (ThisHalfSize.y + OtherHalfSize.y);

    if (IntersectX < 0.0f && IntersectY < 0.0f) {

        push = std::min(std::max(push, 0.0f), 1.0f);

        if (abs(IntersectX) < abs(IntersectY)) {

            if (deltaX > 0.0f) {

                Move(IntersectX * (1.0f - push), 0.0f);
                other.Move(-IntersectX * push, 0.0f);

            } else {
                Move(-IntersectX * (1.0f - push), 0.0f);
                other.Move(IntersectX * push, 0.0f);

            }
        } else {
            if (deltaY > 0.0f) {

                Move(0.0f, IntersectY * (1.0f - push));
                other.Move(0.0f, -IntersectY * push);


            } else {

                Move(0.0f, -IntersectY *(1.0f - push));
                other.Move(0.0f, IntersectY * push );

            }


        }
        return true;
    }
    return false;
}
