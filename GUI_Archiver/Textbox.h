#pragma once

#include "sfmlHeaders.h"
#include <stack>

class TextBox
{
    sf::Text text;
    sf::RectangleShape box;
    sf::Clock clock;

    std::stack<unsigned char> inputText;
    std::string visibleText;
    int characterLimit{ 255 };
    int visibleCharacterLimit{ 10 };
    bool isFocused = false;
public:
    TextBox() = default;

    TextBox(TextBox& textBox) = default;

    TextBox(sf::Font& font, int size, int visibleCharacterLimit, int characterLimit, sf::Vector2f position)
    {
        SetFontText(font);

        SetCharacterSizeText(size);

        SetVisibleCharacterLimit(visibleCharacterLimit);
        SetCharacterLimit(characterLimit);

        SetColorsForBackground(sf::Color::White, sf::Color::Black);
        SetColorText(sf::Color::Black);

        SetOutlineThickness(2);
        SetPosition(position);
    }

    void SetFontText(sf::Font& font_) { text.setFont(font_); }

    void SetCharacterSizeText(int size_)
    {
        text.setCharacterSize(size_);
        ReSizeBox();
    }

    void SetVisibleCharacterLimit(int visibleLimit_)
    {
        visibleCharacterLimit = visibleLimit_;
        ReSizeBox();
    }

    void SetColorText(sf::Color color_) { text.setColor(color_); }

    void SetOutlineThickness(int outlineThickness_) { box.setOutlineThickness(outlineThickness_); }

    void SetColorForOutline(sf::Color outlineColor) { box.setOutlineColor(outlineColor); }

    void SetColorForFill(sf::Color fillColor) { box.setFillColor(fillColor); }

    void SetColorsForBackground(sf::Color fillColor, sf::Color outlineColor)
    {
        box.setFillColor(fillColor);
        box.setOutlineColor(outlineColor);
    }

    void SetCharacterLimit(int limit_) { characterLimit = limit_; }

    void SetPosition(sf::Vector2f position_)
    {
        text.setPosition(position_);
        box.setPosition(position_);
    }

    void Update(sf::RenderWindow& window, sf::Event& event)
    {
        if (isFocused)
        {
            if (event.type == sf::Event::TextEntered && inputText.size() != characterLimit)
            {
                if (std::isprint(event.text.unicode))
                    inputText.push(event.text.unicode);
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (!inputText.empty() &&
                    sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) &&
                    (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)))
                {
                    while (!inputText.empty() && inputText.top() != ';')
                        inputText.pop();
                }
                else if (event.key.code == sf::Keyboard::BackSpace && !inputText.empty())
                {
                    inputText.pop();
                }
            }

            std::stack<unsigned char> copyInputText = inputText;
            std::stack<unsigned char> reverseInputText;
            for (size_t i = 0; i < visibleCharacterLimit && !copyInputText.empty(); ++i)
            {
                reverseInputText.push(copyInputText.top());
                copyInputText.pop();
            }

            visibleText = "";
            while (!reverseInputText.empty())
            {
                visibleText += reverseInputText.top();
                reverseInputText.pop();
            }
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

            if (box.getGlobalBounds().contains(mousePosF))
            {
                isFocused = true;
            }
            else
            {
                isFocused = false;
            }
        }
    }

    void Tick()
    {
        static sf::Time text_effect_time;
        static bool show_cursor;

        if (!isFocused)
        {
            text.setString(visibleText);
            return;
        }

        text_effect_time += clock.restart();
        if (text_effect_time >= sf::seconds(0.5f))
        {
            show_cursor = !show_cursor;
            text_effect_time = sf::Time::Zero;
        }
        if (show_cursor)
        {
            text.setString(visibleText + '_');
        }
        else
        {
            text.setString(visibleText);
        }
    }

    void DrawTo(sf::RenderWindow& window)
    {
        window.draw(box);
        window.draw(text);
    }

    std::string GetText() { return text.getString(); }

private:
    void ReSizeBox()
    {
        int text_lenght = visibleCharacterLimit;
        int text_size = text.getCharacterSize();

        box.setSize(sf::Vector2f(text_size * ((text_lenght) / 1.6), text_size + (text_size * 0.3)));
    }
};