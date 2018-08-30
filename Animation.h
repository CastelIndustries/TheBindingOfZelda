//
// Created by frangio on 24/04/18.
//

#include <SFML/Graphics.hpp>

#ifndef SFML_TESTS_ANIMATION_H
#define SFML_TESTS_ANIMATION_H


class Animation {
public:
    Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();

    void Update(int row, float deltaTime);


public:
    const sf::Vector2u &getImageCount() const;

    void setImageCount(const sf::Vector2u &imageCount);

    float getSwitchTime() const;

    void setSwitchTime(float switchTime);

    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;
};


#endif //SFML_TESTS_ANIMATION_H
