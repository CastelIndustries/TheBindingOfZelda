cmake_minimum_required(VERSION 3.10)
project(sfml_tests_link)

set(CMAKE_CXX_STANDARD 11)

#Define sources and executable
set(EXECUTABLE_NAME "TheBindingOfZelda")
add_executable(${EXECUTABLE_NAME} main.cpp Animation.cpp Animation.h Player.cpp Player.h Coin.cpp Coin.h Block.cpp Block.h Element.cpp Element.h Maps.cpp Maps.h Character.cpp Character.h Skeleton.cpp Skeleton.h RangedCharacter.cpp RangedCharacter.h MeleeCharacter.cpp MeleeCharacter.h Ghost.cpp Ghost.h KungFuRabbit.cpp KungFuRabbit.h CharacterFactory.cpp CharacterFactory.h RangedCharacterFactory.cpp RangedCharacterFactory.h MeleeCharacterFactory.cpp MeleeCharacterFactory.h Collider.cpp Collider.h)

#Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED graphics audio window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()