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

class Character : public Subject  {

public:

    sf::RectangleShape body;

    sf::Clock clock;

    Character();

    virtual  ~Character();

    virtual void Update(float deltaTime, sf::RenderWindow &window)=0;

    virtual void Draw(sf::RenderWindow &window);

    virtual void Create(float deltaTime, sf::RenderWindow &window);

    virtual void RangedAttack();

    virtual void ArtificialIntelligence(Character &player, float deltaTime, sf::RenderWindow &window) = 0;

    Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);

    Collider GetCollider() {
        return Collider(body);
    }

    bool isFiring= false;

    int dirRanAtt;
    int hp=100;
    int kills;
    int l_kills;
    sf::Clock BulletClock;
    bool roomCompletedText;
    bool doorNewLevel;
    sf::Vector2f defaultPos;
    std::vector<Bullet> BulletVec;
    sf::Time ShootDelay;
    bool look=false;
    bool NewLevel = false;


protected:
    float speed, dash;

    Animation animation;
    unsigned int row;

};


#endif //SFML_TESTS_LINK_CHARACTER_H
