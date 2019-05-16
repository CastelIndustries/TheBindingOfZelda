//
// Created by nicola on 06/03/19.
//

#include <iostream>
#include "Bullet.h"
Bullet::Bullet(std::string filename, sf::Vector2f size, int dir) {
    bullet.setSize(size);
    bullet.setOrigin(bullet.getGlobalBounds().width /2, bullet.getGlobalBounds().height/2);
    if(!bulletTexture.loadFromFile(filename))
        std::cout<< filename + " not loaded" << std::endl;
    bullet.setTexture(&bulletTexture);
    bullet.setFillColor(sf::Color::Red);
    BulletDir=dir;
    damage=100;
}
void Bullet::fire(float speed) {
    if (BulletDir==0){

        bullet.move(-speed,0);
    }else{
        if(BulletDir==1){
            bullet.move(0,-speed);
        }else{
            if(BulletDir==2){
                bullet.move(speed,0);
            }else{
                if(BulletDir==3){
                    bullet.move(0,speed);
                }
            }
        }
    }
}

bool Bullet::CheckCollision(sf::RectangleShape &character) {

    //Collision if shooting right
    if (getRight() < character.getPosition().x + character.getSize().x && getRight() > character.getPosition().x) {
        if (getBottom() < character.getPosition().y + character.getSize().y &&
            getBottom() > character.getPosition().y) {
            if (getTop() < character.getPosition().y && getTop() > character.getPosition().y + character.getSize().y) {
                return true;
            }
        }
    }

    //Collision if shooting left
    if (getLeft() > character.getPosition().x && getLeft() < character.getPosition().x + character.getSize().x) {
        if (getBottom() < character.getPosition().y + character.getPosition().y &&
            getBottom() > character.getPosition().y) {
            if (getTop() < character.getPosition().y && getTop() > character.getPosition().y + character.getSize().y) {
                return true;
            }
        }
    }

    //Collision if shooting above
    if (getTop() <  character.getPosition().y && getTop() > character.getPosition().y + character.getSize().y){
        if(getRight() <  character.getPosition().x + character.getSize().x){
            if(getLeft() < character.getPosition().x + character.getSize().x && getLeft() > character.getPosition().x ){
                return true;
            }
        }
    }

    //Collision if shooting down
    if (getBottom() < character.getPosition().y + character.getSize().y && getBottom() > character.getPosition().y) {
        if (getRight() < character.getPosition().x + character.getSize().x) {
            if (getLeft() < character.getPosition().x + character.getSize().x &&
                getLeft() > character.getPosition().x) {
                return true;
            }
        }
    }
    return  false;
}
void Bullet::Draw(sf::RenderWindow &window) {
    window.draw(bullet);
}

void Bullet::setPos(sf::Vector2f NewPos) {
    bullet.setPosition(NewPos);
}

const sf::RectangleShape &Bullet::getBullet() const {
    return bullet;
}

void Bullet::setBullet(const sf::RectangleShape &bullet) {
    Bullet::bullet = bullet;
}
