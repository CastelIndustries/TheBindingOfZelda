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
    sf::RenderWindow window(sf::VideoMode(700, 700), "Legend of Zelda", sf::Style::Close);
    bool isFullscreen = true;
    //BACKGROUND
    /*sf::Texture textBackground;
    textBackground.loadFromFile("/home/frangio/Scaricati/grass.jpg");
    sf::Sprite back;
    textBackground.setRepeated(true);
    back.setTexture(textBackground);
    back.setScale(sf::Vector2f(2.f, 2.f));
    back.scale(sf::Vector2f(0.5f, 0.25f));*/
    srand((unsigned)time(nullptr));
    Maps map;
    //sf::View view ( sf::Vector2f(337.5,337.5), sf::Vector2f (225, 225));
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
    int nCoin=10;
    std::vector<Coin*> coins;
    for (int i=0; i<rCoin; i++) {
        coins.push_back(new Coin(&coinTexture, sf::Vector2u(6, 1), 0.08f, 10, 200.0f + 60.0f * i, 206.0f));
        coins.push_back(new Coin(&coinTexture, sf::Vector2u(6, 1), 0.08f, 10, 200.0f + 60.0f * i, 266.0f));
    }

    //TEXT
    sf::Font font;
    font.loadFromFile("../Textures/Triforce.ttf");
    sf::Text pickedCoins;
    pickedCoins.setFont(font);
    pickedCoins.setPosition(window.getSize().x - pickedCoins.getCharacterSize()*5, 0);
    pickedCoins.setFillColor(sf::Color::Yellow);


    float deltaTime;
    sf::Clock clock;
    int count=0;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::F11:
                            if(isFullscreen){
                                window.create(sf::VideoMode(1366,768), "Legend of Zelda!", sf::Style::Default);
                                isFullscreen=false;
                            }
                            else
                            {
                                window.create(sf::VideoMode(1366,768), "Legend of Zelda!", sf::Style::Fullscreen);
                                isFullscreen=true;
                            }
                            break;
                    }
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::Resized:
                    sf::FloatRect visibleArea(0,0, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));
                    pickedCoins.setPosition(window.getSize().x - pickedCoins.getCharacterSize()*5, 0);

                    break;


            }
        }
        //WINDOW
        window.clear();
        map.showMaps(window);
        //window.setView(view);

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