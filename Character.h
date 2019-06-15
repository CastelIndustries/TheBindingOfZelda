//
// Created by nicola on 8/28/18.
//

#ifndef SFML_TESTS_LINK_CHARACTER_H
#define SFML_TESTS_LINK_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "time.h"
#include "Collider.h"
#include <vector>
#include "Bullet.h"
#include "iostream"
#include "Subject.h"
#include "Strategy.h"

class Character : public Subject {

public:

    sf::RectangleShape body;

    sf::Clock clock;

    Character();

    virtual  ~Character();

    virtual void Update(float deltaTime, sf::RenderWindow &window)=0;

    virtual void Draw(sf::RenderWindow &window);

    virtual void Create(float deltaTime, sf::RenderWindow &window);

    virtual void RangedAttack() = 0;

    virtual void Attack(Character &player, float deltaTime, sf::RenderWindow &window) {};


    virtual void ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) = 0;

    Character(std::string filename, sf::Vector2u imageCount, float switchTime, float speed);

    void setStrategy(Strategy *str);

    Collider GetCollider() {
        return Collider(body);
    }

    bool isFiring= false;

    float distance;
    int hp;
    sf::Clock BulletClock;
    sf::Clock PunchClock;
    bool roomCompletedText;
    bool doorNewLevel;
    int kills=0;
    int l_kills;
    sf::Vector2f defaultPos;
    std::vector<Bullet> BulletVec;
    sf::Time ShootDelay;
    bool best = false;
    sf::Vector2f playerDir;
    bool punching = false;
    Strategy *str;
    bool ranged;



protected:
    float speed, dash;

    Animation animation;
    unsigned int row;

};


#endif //SFML_TESTS_LINK_CHARACTER_H
