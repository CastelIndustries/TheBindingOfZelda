//
// Created by frangio on 03/04/19.
//

#include <iostream>
#include "Menu.h"


Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("../Textures/font.ttf"))
    {
        std::cout<<"Error loading font.ttf" << std::endl;
    }

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("PLAY");
    menu[0].setOrigin(menu[0].getGlobalBounds().width/2, menu[0].getGlobalBounds().height/2);
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));



    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("EXIT");
    menu[1].setOrigin(menu[1].getGlobalBounds().width/2, menu[1].getGlobalBounds().height/2);
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    selectedItemIndex = 0;


    texts[0].setFont(font);
    texts[0].setString("THE BINDING OF ZELDA");
    texts[0].setOrigin(texts[0].getGlobalBounds().width/2, texts[0].getGlobalBounds().height/2);
    texts[0].setPosition(sf::Vector2f(width/2, height / 2));


    texts[1].setFont(font);
    texts[1].setString("Use arrows to navigate. Press ENTER to confirm.");
    texts[1].setScale(0.5f, 0.5f);
    texts[1].setOrigin(texts[1].getGlobalBounds().width, texts[1].getGlobalBounds().height);
    texts[1].setPosition(sf::Vector2f(width / 2, height - 20));

    texts[2].setFont(font);
    texts[2].setString("Use WASD to move. Use arrows to shoot.");
    texts[2].setScale(0.5f, 0.5f);
    texts[2].setOrigin(texts[2].getGlobalBounds().width, texts[2].getGlobalBounds().height);
    texts[2].setPosition(sf::Vector2f(width / 2, height / 2));

    clock.restart();
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(texts[0]);

    if(clock.getElapsedTime().asSeconds() > 1) {
        window.clear();
        for (int i = 0; i < MAX_NUMBER_OF_ITEMS -2; i++) {
            window.draw(menu[i]);
        }


        window.draw(texts[1]);
    }

}

void Menu::moveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS - 2 )
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

bool Menu::instructions(sf::RenderWindow &window) {

    window.clear();
    window.draw(texts[2]);
    if(clock.getElapsedTime().asSeconds() > 1)
        return true;
    else
        return false;

}

bool Menu::dead(sf::RenderWindow &window)
{
    clock.restart();
    window.clear();
    std::cout<<"sei  morto"<<std::endl;
    window.draw(texts[3]);
    if(clock.getElapsedTime().asSeconds() > 30)
        return true;
    else
        return false;
}

