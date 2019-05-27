cmake_minimum_required(VERSION 3.10)
project(TheBindingOfZeldaProject)

set(CMAKE_CXX_STANDARD 11)

#Define sources and executable
set(EXECUTABLE_NAME "TheBindingOfZelda")
set(SOURCES ./Animation.cpp ./Animation.h ./Player.cpp ./Player.h ./Element.cpp ./Element.h ./Character.cpp ./Character.h ./Skeleton.cpp ./Skeleton.h ./RangedCharacter.cpp ./RangedCharacter.h ./MeleeCharacter.cpp ./MeleeCharacter.h ./Ghost.cpp ./Ghost.h ./KungFuRabbit.cpp ./KungFuRabbit.h ./CharacterFactory.cpp ./CharacterFactory.h ./Collider.cpp ./Collider.h ./TileMap.cpp ./TileMap.h ./Bullet.cpp ./Bullet.h ./Tile.cpp ./Tile.h ./HUD.cpp ./HUD.h ./Subject.h ./Observer.h ./ObserverReward.cpp ./ObserverReward.h ./State.h ./StateMachine.cpp ./StateMachine.h ./AssetManager.cpp ./AssetManager.h ./InputManager.cpp ./InputManager.h ./Game.cpp ./Game.h SplashState.cpp SplashState.h DEFINITIONS.h MainMenuState.cpp MainMenuState.h ./GameState.cpp ./GameState.h ./NextLevel.cpp ./NextLevel.h ./PauseState.cpp ./PauseState.h ./GameOverState.cpp ./GameOverState.h)
add_executable(${EXECUTABLE_NAME} ${SOURCES} main.cpp )

#add_subdirectory(TheBindingOfZeldaTests)
#Detect and add SFML
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML  graphics audio window system)
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML REQUIRED graphics audio window system )
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()