#pragma once
#include "sfmlHeaders.h"

class Button
{
    sf::RectangleShape button;
    sf::Text text;

    int btnWidth;
    int btnHeight;
public:
    Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor)
    {
        button.setSize(buttonSize);
        button.setFillColor(bgColor);

        btnWidth = buttonSize.x;
        btnHeight = buttonSize.y;

        text.setString(btnText);
        text.setCharacterSize(charSize);
        text.setColor(textColor);
    }

    void setFont(sf::Font& fonts) { text.setFont(fonts); }

    void setBackColor(sf::Color color) { button.setFillColor(color); }

    void setTextColor(sf::Color color) { text.setColor(color); }

    void setPosition(sf::Vector2f point)
    {
        button.setPosition(point);

        float xPos = ((point.x + btnWidth / 2) - ((text.getString().getSize() * text.getCharacterSize() / 3.25)));
        float yPos = ((point.y + btnHeight / 2) - (text.getCharacterSize() * 1.3 / 2));
        text.setPosition(xPos, yPos);
    }

    void drawTo(sf::RenderWindow& window)
    {
        window.draw(button);
        window.draw(text);
    }

    void Update(sf::RenderWindow& window, sf::Event& event)
    {
        static sf::Color btnColor = button.getFillColor();
        sf::Color delColor(15, 15, 15);
        if (isMouseOver(window))
        {
            button.setFillColor(btnColor + delColor);
        }
        else
        {
            button.setFillColor(btnColor);
        }
    }

    bool Click(sf::RenderWindow& window, sf::Event& event)
    {
        return (isMouseOver(window) && event.type == sf::Event::MouseButtonPressed);
    }

    bool isMouseOver(sf::RenderWindow& window)
    {
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        int btnPosX = button.getPosition().x;
        int btnPosY = button.getPosition().y;

        int btnxPosWidth = button.getPosition().x + btnWidth;
        int btnyPosHeight = button.getPosition().y + btnHeight;

        if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
        {
            return true;
        }
        return false;
    }
};