#pragma once
#include "sfmlHeaders.h"

void UnarchiverScreen(sf::RenderWindow& window)
{
    window.create(sf::VideoMode(700, 480), "Unarchiver - Archiver.Alzip", sf::Style::Titlebar | sf::Style::Close);

    sf::Color backgroundColor(40, 6, 113);
    sf::Color forvardBackgroundColor(67, 18, 174);

    sf::Color colorForButton(116, 70, 215);
    sf::Color colorForTextButton(255, 255, 255);

    sf::Color colorForBackgroundField(142, 109, 215);
    sf::Color colorForTextField(0, 0, 0);

    sf::Vector2f sizeTextField(313, 30);
    int sizeTextInField = 20;

    sf::RectangleShape background = 
        getBackground(backgroundColor, sf::Vector2f(700, 480), sf::Vector2f(0, 0));

    sf::RectangleShape forvardBackground
        = getBackground(forvardBackgroundColor, sf::Vector2f(650, 430), sf::Vector2f(25, 25));

    sf::Font font;
    font.loadFromFile("Resources\\Fonts\\notomono-regular.ttf");

    TextBox textbox1(font, 20, 25, 2550, sf::Vector2f(50, 135));
    TextBox textbox2(font, 20, 25, 255, sf::Vector2f(50, 195));

    Button buttonExit("Exit", sf::Vector2f(75, 35), 20, colorForButton, colorForTextButton);
    buttonExit.setPosition(sf::Vector2f(50, 50));
    buttonExit.setFont(font);

    Button buttonWhat("?", sf::Vector2f(25, 35), 20, colorForButton, colorForTextButton);
    buttonWhat.setPosition(sf::Vector2f(135, 50));
    buttonWhat.setFont(font);

    Button buttonUnzip("Unzip", sf::Vector2f(240, 40), 20, colorForButton, colorForTextButton);
    buttonUnzip.setPosition(sf::Vector2f(400, 390));
    buttonUnzip.setFont(font);

    TextField nameMode("Unzip archive", sf::Vector2f(195, 35), 20, colorForBackgroundField, colorForTextField);
    nameMode.setPosition(sf::Vector2f(170, 50));
    nameMode.setFont(font);

    TextField nameNewArchive(
        "Name archive(s)", sizeTextField, sizeTextInField, colorForBackgroundField, colorForTextField
    );
    nameNewArchive.setPosition(sf::Vector2f(50, 102));
    nameNewArchive.setFont(font);

    TextField directoryForArchive(
        "Directory for unzip", sizeTextField, sizeTextInField, colorForBackgroundField, colorForTextField
    );
    directoryForArchive.setPosition(sf::Vector2f(50, 163));
    directoryForArchive.setFont(font);

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
            else if (buttonWhat.Click(window, event))
            {
                window.close();
                break;
            }
            else if (buttonUnzip.Click(window, event))
            {
                std::string archivesNameInString = textbox1.GetText();
                std::vector<std::string> archiveName = SplitString(archivesNameInString, ';');
                std::string directoryName = textbox2.GetText();

                if (archiveName.empty())
                {
                    cout << "Enter at least one archive to unarchiver!\n";
                    logFile.Error("Enter at least one archive to unarchiver!\n");
                    break;
                }
                try
                {
                    unzip(archiveName, directoryName);
                }
                catch (exception& ex)
                {
                    cout << ex.what();
                }

                break;
            }
            textbox1.Update(window, event);
            textbox2.Update(window, event);


            buttonExit.Update(window, event);
            buttonWhat.Update(window, event);
            buttonUnzip.Update(window, event);
        }
        textbox1.Tick();
        textbox2.Tick();

        window.clear();
        window.draw(background);
        window.draw(forvardBackground);

        nameMode.drawTo(window);
        nameNewArchive.drawTo(window);
        directoryForArchive.drawTo(window);

        buttonExit.drawTo(window);
        buttonWhat.drawTo(window);
        buttonUnzip.drawTo(window);

        textbox1.DrawTo(window);
        textbox2.DrawTo(window);

        window.display();
    }
}