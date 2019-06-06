#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "../Skeleton.h"
#include "../Ghost.h"
#include "../KungFuRabbit.h"
#include "iostream"
#include <list>
#include "../CharacterFactory.h"
#include "../DEFINITIONS.h"
#include "googletest/include/gtest/gtest.h"


TEST(Collisions, CharactersColliding) {
    CharacterFactory characterFactory;

    std::unique_ptr<Character> skeleton = characterFactory.Create(type::SKELETON, SKELETON_TEXTURE,
                                                                  SKELETON_IMAGE_COUNT, SKELETON_SWITCH_TIME,
                                                                  SKELETON_SPEED);
    std::unique_ptr<Character> ghost = characterFactory.Create(type::GHOST, GHOST_TEXTURE, GHOST_IMAGE_COUNT,
                                                               GHOST_SWITCH_TIME, GHOST_SPEED);

    skeleton->body.setPosition(sf::Vector2f(50, 50));
    ghost->body.setPosition(sf::Vector2f(50, 50));

    EXPECT_EQ(true, skeleton->GetCollider().CheckCollision(ghost->GetCollider(), 0.0f));
}

TEST(Damaging, Skeleton_damaging) {
    CharacterFactory characterFactory;

    std::unique_ptr<Character> skeleton = characterFactory.Create(type::SKELETON, SKELETON_TEXTURE,
                                                                  SKELETON_IMAGE_COUNT, SKELETON_SWITCH_TIME,
                                                                  SKELETON_SPEED);


    skeleton->body.setPosition(100, 0);
    Bullet newBullet("tibi", sf::Vector2f(30, 30), sf::Vector2f(1.0f, 0.0f));
    newBullet.setPos(sf::Vector2f(0.0f, 0.0f));
    newBullet.fire(30.0f);
    if (newBullet.GetCollider().CheckCollision(skeleton->GetCollider(), 0.0f)) {
        skeleton->hp -= newBullet.damage;
    }

    EXPECT_EQ(100 - newBullet.damage, skeleton->hp);
}

TEST(Damaging, Damaging_Skeleton_From_Left) {
    CharacterFactory characterFactory;

    std::unique_ptr<Character> skeleton = characterFactory.Create(type::SKELETON, SKELETON_TEXTURE,
                                                                  SKELETON_IMAGE_COUNT, SKELETON_SWITCH_TIME,
                                                                  SKELETON_SPEED);
    std::unique_ptr<Character> player = characterFactory.Create(type::PLAYER, PLAYER_TEXTURE, PLAYER_IMAGE_COUNT,
                                                                PLAYER_SWITCH_TIME, PLAYER_SPEED);


    skeleton->body.setPosition(100, 0);
    Bullet newBullet("tibi", sf::Vector2f(30, 30), skeleton->playerDir);

    player->body.setPosition(0.0f, 0.0f);
    newBullet.setPos(sf::Vector2f(player->body.getPosition().x + player->body.getSize().x / 2,
                                  player->body.getPosition().y + player->body.getSize().y / 2));

    player->BulletVec.push_back(newBullet);
    player->BulletVec[0].fire(30.0f);
    if (player->BulletVec[0].GetCollider().CheckCollision(skeleton->GetCollider(), 0.0f)) {
        skeleton->hp -= newBullet.damage;
    }
    EXPECT_EQ(0, skeleton->hp);
}

TEST(Damaging, Player_damaging_from_left) {
    CharacterFactory characterFactory;
    std::unique_ptr<Character> skeleton = characterFactory.Create(type::SKELETON, SKELETON_TEXTURE,
                                                                  SKELETON_IMAGE_COUNT, SKELETON_SWITCH_TIME,
                                                                  SKELETON_SPEED);
    std::unique_ptr<Character> player = characterFactory.Create(type::PLAYER, PLAYER_TEXTURE, PLAYER_IMAGE_COUNT,
                                                                PLAYER_SWITCH_TIME, PLAYER_SPEED);


    Bullet newBullet("tibi", sf::Vector2f(30, 30), player->playerDir);
    player->body.setPosition(100.0f, 0.0f);
    skeleton->body.setPosition(0.0f, 0.0f);
    newBullet.setPos(sf::Vector2f(skeleton->body.getPosition().x + skeleton->body.getSize().x / 2,
                                  skeleton->body.getPosition().y + skeleton->body.getSize().y / 2));

    skeleton->BulletVec.push_back(newBullet);
    skeleton->BulletVec[0].fire(30.0f);
    if (skeleton->BulletVec[0].GetCollider().CheckCollision(player->GetCollider(), 0.0f)) {
        player->hp -= newBullet.damage;
    }
    EXPECT_EQ(0, player->hp);

}
int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}