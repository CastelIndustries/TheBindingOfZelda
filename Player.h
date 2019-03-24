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
            //body.setOrigin(body.getSize()/2.0f);
            body.setPosition(605.5f, 432.5f);
            body.setTexture(texture);
            //body.setFillColor(sf::Color::White);
            kills=0;

    };
    ~Player();

    void RangedAttack() override;

    void Create(float deltaTime, sf::RenderWindow &window) override;

    void Update(float deltaTime, sf::RenderWindow &window) override;

    void CorrectDisplay(sf::RenderWindow &window) override;

    void RegisterObserver (Observer* observer) override;

    void RemoveObserver (Observer* observer) override;

    void NotifyObservers () override;



    sf::Clock BulletClock;

    const sf::Time ShootDelay=sf::seconds(.4f);



    bool reward;


};


#endif //SFML_TESTS_PLAYER_H

