#pragma once
#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include <stack>

using namespace std;

class TextBox
{
    sf::Text text;
    sf::RectangleShape box;
    sf::Clock clock;

    std::stack<char> inputText;
    string visibleText;
    int characterLimit{ 255 };
    int visibleCharacterLimit{ 0 };
    bool isFocused = false;
public:
    TextBox() = default;
    TextBox(TextBox& textBox) = default;

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
    void SetColorText(sf::Color& color_) { text.setColor(color_); }
    void SetOutlineThickness(int outlineThickness_) { box.setOutlineThickness(outlineThickness_); }
    void SetColorForOutline(sf::Color& outlineColor) { box.setOutlineColor(outlineColor); }
    void SetColorForFill(sf::Color& fillColor) { box.setFillColor(fillColor); }
    void SetColorsForBackground(sf::Color& fillColor, sf::Color& outlineColor)
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
                if (event.key.code == sf::Keyboard::BackSpace && !inputText.empty())
                {
                    inputText.pop();
                }
            }

            stack<char> copyInputText = inputText;
            stack<char> reverseInputText;
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
        text.setString(visibleText + (show_cursor ? '_' : ' '));
    }

    void DrawTo(sf::RenderWindow& window)
    {
        window.draw(box);
        window.draw(text);
    }

private:
    void ReSizeBox()
    {
        int text_lenght = visibleCharacterLimit;
        int text_size = text.getCharacterSize();

        box.setSize(sf::Vector2f(text_size * ((text_lenght) / 2 + 1), text_size + (text_size * 0.3)));
        // text_size + (text_size * 0.3) = y
        // text_size * (text_lenght + 1) / 2 = x
    }
};
/*
    sf::Color white = sf::Color::White;
    sf::Color black = sf::Color::Black;

    Textbox textbox;
    textbox.SetCharacterLimit(30);
    textbox.SetCharacterSizeText(25);
    textbox.SetColorForFill(white);
    textbox.SetColorForOutline(black);
    textbox.SetColorsForBackground(white, black);
    textbox.SetColorText(black);
    textbox.SetFontText(font);
    textbox.SetOutlineThickness(2);
    textbox.SetPosition(sf::Vector2f(150, 100));
    textbox.SetVisibleCharacterLimit(30);

    while:
        while event:
            textbox.Update(window, Event);
        
        textbox.Tick();
        textbox.DrawTo(window);
*/