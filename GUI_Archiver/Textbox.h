#pragma once
#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>

using namespace std;

class TextBox
{
    sf::Text text;
    sf::RectangleShape box;
    sf::Clock clock;

    string inputText;
    string visibleText;

    int characterLimit = 255;
    int visibleCharacterLimit;

    bool isFocused = false;
public:
    TextBox() = delete;
    TextBox(TextBox& textBox) = delete;

    TextBox(int size_, sf::Color color_)
    {
        text.setCharacterSize(size_);
        text.setColor(color_);

        box.setSize(sf::Vector2f(visibleCharacterLimit * size_ * 5, size_ * 1.5));
        box.setFillColor(sf::Color::White);
        box.setOutlineColor(sf::Color::Black);
        box.setOutlineThickness(2);
    }
    void SetFont(sf::Font& fontForText) { text.setFont(fontForText); }
    void SetCharacterLimit(int limit_) { characterLimit = limit_; }
    void SetVisibleCharacterLimit(int visibleLimit_) { visibleCharacterLimit = visibleLimit_; }

    void SetCharacterSize(int size_) { text.setCharacterSize(size_); }
    void SetVisibleCharacterLimit(int limit) { visibleCharacterLimit = limit; }

    void SetColorForText(sf::Color& colorForText) { text.setColor(colorForText); }
    void SetColorsForBackgrounds(sf::Color& fillColor, sf::Color& outlineColor)
    {
        box.setFillColor(fillColor);
        box.setOutlineColor(outlineColor);
    }

    void Update(sf::RenderWindow& window, sf::Event& event)
    {
        if (isFocused)
        {
            if (event.type == sf::Event::TextEntered)
            {
                if (std::isprint(event.text.unicode))
                    inputText += event.text.unicode;
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::BackSpace && !inputText.empty())
                {
                    inputText.pop_back();
                }
                if (event.key.code == sf::Keyboard::Return)
                {
                    inputText += '\n';
                }
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

        static sf::Time text_effect_time;
        static bool show_cursor;

        text_effect_time += clock.restart();

        if (text_effect_time >= sf::seconds(0.5f))
        {
            show_cursor = !show_cursor;
            text_effect_time = sf::Time::Zero;
        }

        text.setString(inputText + (show_cursor ? '_' : ' '));
    }

    void SetPosition(sf::Vector2f point)
    {
        text.setPosition({ point.x + text.getCharacterSize() * 0.2, point.y + text.getCharacterSize() * 0.2 });
        box.setPosition(point);
    }

    void DrawTo(sf::RenderWindow& window)
    {
        window.draw(box);
        window.draw(text);
    }
};