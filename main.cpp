#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Animation.h"
#include "Player.h"
#include "Coin.h"
#include "Maps.h"

int main()
{
    //WINDOW
    sf::RenderWindow window(sf::VideoMode(843, 675), "Binding of Zelda", sf::Style::Close);
    //MAP
    srand((unsigned)time(nullptr));
    Maps map;
    //PLAYER
    sf::Texture playerTexture;
    playerTexture.loadFromFile("../Textures/link4.png");

    Player player(&playerTexture, sf::Vector2u(12, 8), 0.035f, 150.0f);
    //COINS
    sf::Texture coinTexture;
    coinTexture.loadFromFile("../Textures/coin.png");
    sf::SoundBuffer buffer;
    buffer.loadFromFile("../Textures/smw_coin.wav");
    sf::Sound coinSound;
    coinSound.setBuffer(buffer);

    int rCoin=5;
    int nCoin = 5;
    std::vector<Coin*> coins;
    for (int i=0; i<rCoin; i++) {
        coins.push_back(new Coin(&coinTexture, sf::Vector2u(6, 1), 0.08f, 10, 200.0f + 60.0f * i, 206.0f));
    }

    //TEXT
    sf::Font font;
    font.loadFromFile("../Textures/Triforce.ttf");
    sf::Text pickedCoins;
    pickedCoins.setFont(font);
    pickedCoins.setPosition(window.getSize().x - pickedCoins.getCharacterSize()*5, 0);
    pickedCoins.setColor(sf::Color::Yellow);



    float deltaTime;
    sf::Clock clock;
    int count=0;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::Resized:
                    sf::FloatRect visibleArea(0, 0, evnt.size.width, evnt.size.height);
                    window.setView(sf::View(visibleArea));
                    pickedCoins.setPosition(window.getSize().x - pickedCoins.getCharacterSize()*5, 0);

                    break;
            }
        }
        //WINDOW
        window.clear();
        map.showMaps(window);
        //PLAYER
        player.Update(deltaTime, window);
        player.Draw(window);
        player.CorrectDisplay(window);
        //COINS
        for (auto coin : coins) {
            coin->rotate(deltaTime);
            coin->Draw(window);
        }
        //PICKING COINS
        for(int i=0; i<nCoin; i++){
            if(player.playerBorder.getGlobalBounds().intersects(coins[i]->coinBorder.getGlobalBounds())){
                coins.erase(coins.begin() + i);
                nCoin--;
                count++;
                coinSound.play();
            }
        }
        pickedCoins.setString("COINS : "+ std::to_string(count));
        window.draw(pickedCoins);


        window.display();
    }

    return 0;
}