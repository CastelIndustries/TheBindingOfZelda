//
// Created by nicola on 16/03/19.
//

#ifndef SFML_TESTS_LINK_OBSERVERREWARD_H
#define SFML_TESTS_LINK_OBSERVERREWARD_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Observer.h"
#include "Element.h"


class ObserverReward : public Observer {
public:

    ObserverReward() {};

    void newLevel(TileMap &map, sf::RenderWindow &window) override;
    void update(TileMap &map, sf::RenderWindow &window) override;
    void key(Element* &key, sf::RenderWindow &window) override;
private:
    Element* _key = new Element(538, 175, "../Textures/chiave.png", 0.3, 0.3);

};


#endif //SFML_TESTS_LINK_OBSERVERREWARD_H
