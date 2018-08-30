//
// Created by frangio on 24/04/18.
//

#include "Animation.h"

Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime) {

    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / imageCount.x;
    uvRect.height = texture->getSize().y / imageCount.y;
}

Animation::~Animation() {}

void Animation::Update(int row, float deltaTime) {

    currentImage.y = row;
    totalTime += deltaTime;

    if (totalTime >= switchTime) {

        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.x >= imageCount.x)
            currentImage.x = 0;
    }
    uvRect.top = currentImage.y * uvRect.height;
    uvRect.left = currentImage.x * uvRect.width;
    uvRect.width = abs(uvRect.width);
}

float Animation::getSwitchTime() const {
    return switchTime;
}

void Animation::setSwitchTime(float switchTime) {
    Animation::switchTime = switchTime;
}

const sf::Vector2u &Animation::getImageCount() const {
    return imageCount;
}

void Animation::setImageCount(const sf::Vector2u &imageCount) {
    Animation::imageCount = imageCount;
}
