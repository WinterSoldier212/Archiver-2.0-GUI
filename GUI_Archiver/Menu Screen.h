#pragma once

#include "Archiver Screen.h"
#include "Unarchiver Screen.h"

void MenuScreen(sf::RenderWindow& window)
{
    sf::Color backgroundColor(40, 6, 113);
    sf::Color forvardBackgroundColor(67, 18, 174);

    sf::Color colorForButton(116, 70, 215);
    sf::Color colorForTextButton(255, 255, 255);

    window.create(sf::VideoMode(700, 480), "Menu - Archiver.Alzip", sf::Style::Titlebar | sf::Style::Close);
    window.setKeyRepeatEnabled(true);

    sf::RectangleShape background =
        getBackground(backgroundColor, sf::Vector2f(700, 480), sf::Vector2f(0, 0));

    sf::RectangleShape forvardBackground =
        getBackground(forvardBackgroundColor, sf::Vector2f(650, 430), sf::Vector2f(25, 25));

    sf::Font font;
    font.loadFromFile("Resources\\Fonts\\notomono-regular.ttf");

    Button buttonArchiver("Archiver", sf::Vector2f(233, 80), 30, colorForButton, colorForTextButton);
    buttonArchiver.setPosition(sf::Vector2f(233, 100));
    buttonArchiver.setFont(font);

    Button buttonUnarchiver("Unarchiver", sf::Vector2f(233, 80), 30, colorForButton, colorForTextButton);
    buttonUnarchiver.setPosition(sf::Vector2f(233, 200));
    buttonUnarchiver.setFont(font);

    Button buttonExit("Exit", sf::Vector2f(233, 80), 30, colorForButton, colorForTextButton);
    buttonExit.setPosition(sf::Vector2f(233, 300));
    buttonExit.setFont(font);

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
            if (buttonExit.Click(window, event))
            {
                window.close();
                break;
            }
            else if (buttonArchiver.Click(window, event))
            {
                window.close();
                ArchiverScreen(window); 
                window.create(sf::VideoMode(700, 480), "Menu - Archiver.Alzip", sf::Style::Titlebar | sf::Style::Close);
            }
            else if (buttonUnarchiver.Click(window, event))
            {
                window.close();
                UnarchiverScreen(window);
                window.create(sf::VideoMode(700, 480), "Menu - Archiver.Alzip", sf::Style::Titlebar | sf::Style::Close);
            }
            buttonExit.Update(window, event);
            buttonArchiver.Update(window, event);
            buttonUnarchiver.Update(window, event);
        }

        window.clear();
        window.draw(background);
        window.draw(forvardBackground);

        buttonExit.drawTo(window);
        buttonArchiver.drawTo(window);
        buttonUnarchiver.drawTo(window);

        window.display();
    }
    window.close();
}