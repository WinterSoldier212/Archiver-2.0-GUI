#pragma once
#include <SFML/Graphics.hpp>

#define WINDOW_LOADING_SCREEN_LIFETIME 3.0f

void LoadingScreen(sf::RenderWindow& window)
{
    window.create(sf::VideoMode(512, 256), "Loading Screen... - Archiver.alzip", sf::Style::None);

    sf::Texture texture;
    texture.loadFromFile("Resources\\Images\\LoadingScreen.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Clock clock;
    float elapsedTime = 0.0f;

    while (window.isOpen() && elapsedTime < WINDOW_LOADING_SCREEN_LIFETIME)
    {
        elapsedTime = clock.getElapsedTime().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    window.close();
}