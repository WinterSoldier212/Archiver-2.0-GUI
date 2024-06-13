#pragma once

#include "Textbox.h"
#include "Button.h"

void ArchiverScreen(sf::RenderWindow& window)
{
    window.create(sf::VideoMode(700, 480), "Archiver - Archiver.Alzip", sf::Style::Titlebar | sf::Style::Close);

    while (window.isOpen())
    {
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
        window.display();
    }
    window.close();
}