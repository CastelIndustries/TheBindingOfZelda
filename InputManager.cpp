//
// Created by frangio on 23/05/19.
//

#include "InputManager.h"



bool InputManager::IsTextSelectioned(sf::Text text, sf::RenderWindow &window)
{
    sf::IntRect playButtonRect(text.getPosition().x - text.getGlobalBounds().width/2.0f , text.getPosition().y - text.getGlobalBounds().height / 2.0f, text.getGlobalBounds().width, text.getGlobalBounds().height);

    return playButtonRect.contains(sf::Mouse::getPosition(window));


}

