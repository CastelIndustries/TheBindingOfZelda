#include "ObserverReward.h"
#include "iostream"
#include "TileMap.h"
#include "CharacterFactory.h"
#include "NextLevel.h"
#include "MainMenuState.h"

void ObserverReward::newLevel(GameDataRef &_data) {

    if(_data->numEnemies < 5)
        _data->numEnemies++;
    _data->machine.AddState(StateRef(new NextLevel(_data)), true);


}

void ObserverReward::update(TileMap &map, sf::RenderWindow &window) {

    for (int i = 0; i < map.width; i++) {
        for (int j = 0; j < map.height; j++) {
            if (map.map[j][i] == 3) {
                map.map[j][i] = 4;
            }
        }

    }

    map.load(TILE_SET_TEXTURE, window, true);

}
