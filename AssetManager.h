//
// Created by frangio on 23/05/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_ASSETMANAGER_H
#define THEBINDINGOFZELDAPROJECT_ASSETMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>

class AssetManager
{
public:
    AssetManager() { }
    ~AssetManager() { }

    void LoadTexture(std::string name, std::string fileName);
    sf::Texture &GetTexture(std::string name);

    void LoadFont(std::string name, std::string fileName);
    sf::Font &GetFont(std::string name);

private:

    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
};

#endif //THEBINDINGOFZELDAPROJECT_ASSETMANAGER_H
