//
// Created by nicola on 16/03/19.
//

#ifndef SFML_TESTS_LINK_OBSERVERREWARD_H
#define SFML_TESTS_LINK_OBSERVERREWARD_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Observer.h"
#include "Element.h"
#include "Game.h"
#include "State.h"


class ObserverReward : public Observer {
public:

    ObserverReward() {};

    void newHighScore(GameDataRef &_data, HUD &hud) override;
    void newLevel(GameDataRef &_data) override;
    void update(TileMap &map, sf::RenderWindow &window) override;

private:
    GameDataRef _data;

};


#endif //SFML_TESTS_LINK_OBSERVERREWARD_H
