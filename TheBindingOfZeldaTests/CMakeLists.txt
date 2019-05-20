cmake_minimum_required(VERSION 3.10)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(EXECUTABLE_NAME "TheBindingOfZeldaTests")

project(${EXECUTABLE_NAME})

set(CMAKE_CXX_STANDARD 11)

#Define sources and executable
add_executable(${EXECUTABLE_NAME} ${SOURCES} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} gtest gtest_main)
#Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML  graphics audio window system)
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML REQUIRED graphics audio window system )
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()