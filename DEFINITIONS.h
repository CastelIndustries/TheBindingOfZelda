//
// Created by frangio on 23/05/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_DEFINITIONS_H
#define THEBINDINGOFZELDAPROJECT_DEFINITIONS_H

//WINDOW
#define SCREEN_WIDTH 1211
#define SCREEN_HEIGHT 865

//TIMES
#define INSTRUCTIONS_TIME 2.5
#define SPLASH_STATE_SHOW_TIME 2
#define  NEXT_LEVEL_TIME 2

//CHARACTERS

#define PLAYER_TEXTURE "../Resources/res/player.png"
#define SKELETON_TEXTURE "../Resources/res/skeleton.png"
#define GHOST_TEXTURE "../Resources/res/ghost.png"
#define RABBIT_TEXTURE "../Resources/res/rabbit.png"

#define PLAYER_IMAGE_COUNT sf::Vector2u(3, 6)
#define SKELETON_IMAGE_COUNT sf::Vector2u(3, 4)
#define GHOST_IMAGE_COUNT sf::Vector2u(2, 4)
#define RABBIT_IMAGE_COUNT sf::Vector2u(2, 4)

#define PLAYER_SWITCH_TIME 0.1f
#define SKELETON_SWITCH_TIME 0.5f
#define GHOST_SWITCH_TIME 0.3f
#define RABBIT_SWITCH_TIME 0.3f

#define PLAYER_SPEED 15
#define SKELETON_SPEED 10
#define GHOST_SPEED 8
#define RABBIT_SPEED 10

//ELEMENTS

#define HIGHSCORE_FILE "../Resources/res/highscores.txt"

#define PLAYER_BULLET_SPEED 18
#define ENEMY_BULLET_SPEED 12
#define RANGE 1500

#define BLAST_AUDIO "../Resources/res/laser.ogg"
#define CONFIRM_AUDIO "../Resources/res/confirm.ogg"
#define SELECTION_AUDIO "../Resources/res/selection.ogg"
#define SONG_AUDIO "../Resources/res/song.ogg"

#define CHEST_TEXTURE "../Resources/res/tesoro-b.png"
#define BONE_1_TEXTURE "../Resources/res/skeleton 1b.png"
#define BONE_2_TEXTURE "../Resources/res/skeleton 2b.png"
#define BONE_3_TEXTURE "../Resources/res/skeleton 3b.png"

#define BULLET_TEXTURE "../Resources/res/bullet.png"

#define MAX_NUMBER_OF_ITEMS 4

#define NUM_HUD_TEXTS 3


//MAP

#define TILE_SET_TEXTURE "../Resources/res/tileset3.png"
#define MAP_WIDTH 71
#define MAP_HEIGHT 36
#define TILE_SIZE sf::Vector2u(175, 175)
#define MAP_1 "../Resources/res/Map1.txt"
#define MAP_2 "../Resources/res/Map2.txt"
#define MAP_3 "../Resources/res/Map3.txt"

//HUD

#define HEART_TEXTURE "../Resources/res/Heart.png"
#define KILL_TEXT 0
#define ENTER_DOOR_TEXT 1
#define BEST_SCORE_TEXT 2

//FONTS
#define FONT "../Resources/font/font.ttf"




#endif //THEBINDINGOFZELDAPROJECT_DEFINITIONS_H
