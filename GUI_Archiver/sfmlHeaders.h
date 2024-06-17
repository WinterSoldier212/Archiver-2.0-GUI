#pragma once
#pragma warning(disable : 4996)

#include <SFML/Graphics.hpp>
#include "ProgramOptions.h"

#include "TextField.h"
#include "TextBox.h"
#include "Button.h"

std::vector<std::string> SplitString(std::string s, char del)
{
    std::vector<std::string> splitString;
    long long end = s.find(del);
    while (end != -1)
    {
        splitString.push_back(s.substr(0, end));
        s.erase(s.begin(), s.begin() + end + 1);
        end = s.find(del);
    }

    return splitString;
}

sf::RectangleShape getBackground(sf::Color color, sf::Vector2f size, sf::Vector2f position)
{
    sf::RectangleShape background(size);
    background.setFillColor(color);
    background.setPosition(position);

    return background;
}