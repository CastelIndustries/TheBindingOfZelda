//
// Created by frangio on 03/04/19.
//

#ifndef SFML_TESTS_LINK_MENU_H
#define SFML_TESTS_LINK_MENU_H

#include "SFML/Graphics.hpp"


#define MAX_NUMBER_OF_ITEMS 4

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    bool instructions(sf::RenderWindow &window);
    bool dead(sf::RenderWindow &window);
    int GetPressedItem() { return selectedItemIndex; }
    sf::Clock clock;

private:

    int selectedItemIndex;
    sf::Font font;
    sf::Text texts[MAX_NUMBER_OF_ITEMS];
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};


#endif //SFML_TESTS_LINK_MENU_H
