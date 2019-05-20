cmake_minimum_required(VERSION 3.13)
project(untitled3)

set(CMAKE_CXX_STANDARD 14)
#including google test
set(EXECUTABLE_NAME "TheBindingOfZeldaTests")
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})

add_executable(TheBindingOfZeldaTests main.cpp ../Animation.cpp ../Animation.h ../Player.cpp ../Player.h ../Element.cpp ../Element.h ../Character.cpp ../Character.h ../Skeleton.cpp ../Skeleton.h ../RangedCharacter.cpp ../RangedCharacter.h ../MeleeCharacter.cpp ../MeleeCharacter.h ../Ghost.cpp ../Ghost.h ../KungFuRabbit.cpp ../KungFuRabbit.h ../CharacterFactory.cpp ../CharacterFactory.h ../Collider.cpp ../Collider.h ../TileMap.cpp ../TileMap.h ../Bullet.cpp ../Bullet.h ../Tile.cpp ../Tile.h ../HUD.cpp ../HUD.h ../Subject.h ../Observer.h ../ObserverReward.cpp ../ObserverReward.h ../Menu.cpp ../Menu.h)
target_link_libraries(${EXECUTABLE_NAME} gtest gtest_main)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML  graphics audio window system)
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML REQUIRED graphics audio window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()