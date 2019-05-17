cmake_minimum_required(VERSION 3.10)
project(sfml_tests_link)

set(CMAKE_CXX_STANDARD 11)

#Define sources and executable
set(EXECUTABLE_NAME "TheBindingOfZeldaTests")
add_executable(${EXECUTABLE_NAME} main.cpp)
#Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML  graphics audio window system)
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML REQUIRED graphics audio window system )
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()