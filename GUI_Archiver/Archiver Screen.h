#pragma once
#include "sfmlHeaders.h"

void ArchiverScreen(sf::RenderWindow& window)
{
    sf::Color backgroundColor(40, 6, 113);
    sf::Color forvardBackgroundColor(67, 18, 174);

    sf::Color colorForButton(116, 70, 215);
    sf::Color colorForTextButton(255, 255, 255);

    sf::Color colorForBackgroundField(142, 109, 215);
    sf::Color colorForTextField(0, 0, 0);

    sf::Vector2f sizeTextField(313, 30);
    int sizeTextInField = 20;

    window.create(sf::VideoMode(700, 480), "Archiver - Archiver.Alzip", sf::Style::Titlebar | sf::Style::Close);
    window.setKeyRepeatEnabled(true);

    sf::RectangleShape background =
        getBackground(backgroundColor, sf::Vector2f(700, 480), sf::Vector2f(0, 0));

    sf::RectangleShape forvardBackground =
        getBackground(forvardBackgroundColor, sf::Vector2f(650, 430), sf::Vector2f(25, 25));

    sf::Font font;
    font.loadFromFile("Resources\\Fonts\\notomono-regular.ttf");

    TextBox textbox1(font, 20, 25, 255, sf::Vector2f(50, 135));
    TextBox textbox2(font, 20, 25, 255, sf::Vector2f(50, 195));

    TextBox textbox3(font, 20, 25, 2550, sf::Vector2f(50, 255));
    TextBox textbox4(font, 20, 25, 2550, sf::Vector2f(50, 284));
    TextBox textbox5(font, 20, 25, 2550, sf::Vector2f(50, 313));
    TextBox textbox6(font, 20, 25, 2550, sf::Vector2f(50, 342));
    TextBox textbox7(font, 20, 25, 2550, sf::Vector2f(50, 371));
    TextBox textbox8(font, 20, 25, 2550, sf::Vector2f(50, 400));

    Button buttonExit("Exit", sf::Vector2f(75, 35), 20, colorForButton, colorForTextButton);
    buttonExit.setPosition(sf::Vector2f(50, 50));
    buttonExit.setFont(font);

    Button buttonWhat("?", sf::Vector2f(25, 35), 20, colorForButton, colorForTextButton);
    buttonWhat.setPosition(sf::Vector2f(135, 50));
    buttonWhat.setFont(font);

    Button buttonCreate("Create", sf::Vector2f(240, 40), 20, colorForButton, colorForTextButton);
    buttonCreate.setPosition(sf::Vector2f(400, 390));
    buttonCreate.setFont(font);

    TextField nameMode("Archiving files", sf::Vector2f(195, 35), 20, colorForBackgroundField, colorForTextField);
    nameMode.setPosition(sf::Vector2f(170, 50));
    nameMode.setFont(font);

    TextField nameNewArchive(
        "Name new archive", sizeTextField, sizeTextInField, colorForBackgroundField, colorForTextField
    );
    nameNewArchive.setPosition(sf::Vector2f(50, 102));
    nameNewArchive.setFont(font);

    TextField directoryForArchive(
        "Directory for archive", sizeTextField, sizeTextInField, colorForBackgroundField, colorForTextField
    );
    directoryForArchive.setPosition(sf::Vector2f(50, 163));
    directoryForArchive.setFont(font);

    TextField filesForArchive(
        "Files for archive", sizeTextField, sizeTextInField, colorForBackgroundField, colorForTextField
    );
    filesForArchive.setPosition(sf::Vector2f(50, 222));
    filesForArchive.setFont(font);

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
            else if (buttonCreate.Click(window, event))
            {
                std::string archiveName = textbox1.GetText();
                std::string directoryName = textbox2.GetText();

                std::string filesForArchiveInString = textbox3.GetText() +
                    textbox4.GetText() + textbox5.GetText() +
                    textbox6.GetText() + textbox7.GetText() +
                    textbox8.GetText();

                std::vector<std::string> filesForArchive =
                    SplitString(filesForArchiveInString, ';');

                if (filesForArchive.empty())
                {
                    cout << "Enter at least one file to archive!\n";
                    logFile.Error("Enter at least one file to archive!\n");
                    break;
                }
                zip(filesForArchive, directoryName, archiveName);

                break;
            }
            textbox1.Update(window, event);
            textbox2.Update(window, event);
            textbox3.Update(window, event);
            textbox4.Update(window, event);
            textbox5.Update(window, event);
            textbox6.Update(window, event);
            textbox7.Update(window, event);
            textbox8.Update(window, event);

            buttonExit.Update(window, event);
            buttonWhat.Update(window, event);
            buttonCreate.Update(window, event);

        }
        textbox1.Tick();
        textbox2.Tick();
        textbox3.Tick();
        textbox4.Tick();
        textbox5.Tick();
        textbox6.Tick();
        textbox7.Tick();
        textbox8.Tick();

        window.clear();
        window.draw(background);
        window.draw(forvardBackground);

        nameMode.drawTo(window);
        nameNewArchive.drawTo(window);
        directoryForArchive.drawTo(window);
        filesForArchive.drawTo(window);

        buttonExit.drawTo(window);
        buttonWhat.drawTo(window);
        buttonCreate.drawTo(window);

        textbox1.DrawTo(window);
        textbox2.DrawTo(window);
        textbox3.DrawTo(window);
        textbox4.DrawTo(window);
        textbox5.DrawTo(window);
        textbox6.DrawTo(window);
        textbox7.DrawTo(window);
        textbox8.DrawTo(window);

        window.display();
    }
}