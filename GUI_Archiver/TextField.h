#pragma once
#include "sfmlHeaders.h"

class TextField
{
    sf::RectangleShape field;
    sf::Text text;

    int btnWidth;
    int btnHeight;
public:
    TextField(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor)
    {
        field.setSize(buttonSize);
        field.setFillColor(bgColor);

        btnWidth = buttonSize.x;
        btnHeight = buttonSize.y;

        text.setString(btnText);
        text.setCharacterSize(charSize);
        text.setColor(textColor);

        field.setOutlineColor({ 0, 0, 0 });
        field.setOutlineThickness(1);
    }

    void setFont(sf::Font& fonts) { text.setFont(fonts); }

    void setBackColor(sf::Color color) { field.setFillColor(color); }

    void setTextColor(sf::Color color) { text.setColor(color); }

    void setPosition(sf::Vector2f point)
    {
        field.setPosition(point);

        float xPos = ((point.x + btnWidth / 2) - ((text.getString().getSize() * text.getCharacterSize() / 3.25)));
        float yPos = ((point.y + btnHeight / 2) - (text.getCharacterSize() * 1.3 / 2));
        text.setPosition(xPos, yPos);
    }

    void drawTo(sf::RenderWindow& window)
    {
        window.draw(field);
        window.draw(text);
    }
};