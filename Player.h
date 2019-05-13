//
// Created by frangio on 24/04/18.
//


#ifndef SFML_TESTS_PLAYER_H
#define SFML_TESTS_PLAYER_H


#include "RangedCharacter.h"
#include "Collider.h"
#include "Subject.h"
class Player : public RangedCharacter   {
public:

    Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : RangedCharacter(texture,
                                                                                                           imageCount,
                                                                                                           switchTime,
                                                                                                           speed) {
            this->speed = speed;
            dash = speed;
            row = 0;
            body.setSize(sf::Vector2f(120.0f, 210.0f));
            body.setPosition(3000.0f, 1800.0f);
            defaultPos = body.getPosition();
            body.setTexture(texture);
            kills=0;
            l_kills=0;
            roomCompletedText = false;
            doorNewLevel = false;
            this->ShootDelay = sf::seconds(0.4f);

    };
    ~Player();

    void RangedAttack() override;

    void Create(float deltaTime, sf::RenderWindow &window) override;

    void Update(float deltaTime, sf::RenderWindow &window) override;

    void RegisterObserver (Observer* observer) override;

    void RemoveObserver (Observer* observer) override;

    void NotifyObservers (TileMap &map, sf::RenderWindow &window) override;

};


#endif //SFML_TESTS_PLAYER_H

