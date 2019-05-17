cmake_minimum_required(VERSION 3.13)
project(untitled3)

set(CMAKE_CXX_STANDARD 14)
#including google test
add_subdirectory(googletest-master)
target_link_libraries(${EXECUTABLE_NAME} googletest-master)

add_executable(TheBindingOfZeldaTests main.cpp)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML  graphics audio window system)
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML REQUIRED graphics audio window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()